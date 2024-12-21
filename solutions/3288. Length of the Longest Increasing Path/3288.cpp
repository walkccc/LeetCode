class Solution {
 public:
  int maxPathLength(vector<vector<int>>& coordinates, int k) {
    const int xk = coordinates[k][0];
    const int yk = coordinates[k][1];
    vector<pair<int, int>> leftCoordinates;
    vector<pair<int, int>> rightCoordinates;

    for (const vector<int>& coordinate : coordinates) {
      const int x = coordinate[0];
      const int y = coordinate[1];
      if (x < xk && y < yk)
        leftCoordinates.emplace_back(x, y);
      else if (x > xk && y > yk)
        rightCoordinates.emplace_back(x, y);
    }

    return 1 + lengthOfLIS(leftCoordinates) + lengthOfLIS(rightCoordinates);
  }

 private:
  // Similar to 300. Longest Increasing Subsequence
  int lengthOfLIS(vector<pair<int, int>>& coordinates) {
    ranges::sort(coordinates, ranges::less{},
                 [](const pair<int, int>& coordinate) {
      return pair<int, int>{coordinate.first, -coordinate.second};
    });
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    vector<int> tails;
    for (const auto& [_, y] : coordinates)
      if (tails.empty() || y > tails.back())
        tails.push_back(y);
      else
        tails[firstGreaterEqual(tails, y)] = y;
    return tails.size();
  }

  int firstGreaterEqual(const vector<int>& A, int target) {
    return ranges::lower_bound(A, target) - A.begin();
  }
};
