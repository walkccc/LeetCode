class Solution {
 public:
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    int ans = 0;
    vector<int> northernmost(n + 1, INT_MAX);
    vector<int> southernmost(n + 1, 0);
    vector<int> westernmost(n + 1, INT_MAX);
    vector<int> easternmost(n + 1, 0);

    for (const vector<int>& building : buildings) {
      const int x = building[0];
      const int y = building[1];
      northernmost[x] = min(northernmost[x], y);
      southernmost[x] = max(southernmost[x], y);
      westernmost[y] = min(westernmost[y], x);
      easternmost[y] = max(easternmost[y], x);
    }

    for (const vector<int>& building : buildings) {
      const int x = building[0];
      const int y = building[1];
      if (northernmost[x] < y && y < southernmost[x]  //
          && westernmost[y] < x && x < easternmost[y])
        ++ans;
    }

    return ans;
  }
};
