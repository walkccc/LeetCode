class Solution {
 public:
  vector<vector<int>> getSkyline(const vector<vector<int>>& buildings) {
    const int n = buildings.size();
    if (n == 0)
      return {};
    if (n == 1) {
      const int left = buildings[0][0];
      const int right = buildings[0][1];
      const int height = buildings[0][2];
      return {{left, height}, {right, 0}};
    }

    const vector<vector<int>> left =
        getSkyline({begin(buildings), begin(buildings) + n / 2});
    const vector<vector<int>> right =
        getSkyline({begin(buildings) + n / 2, end(buildings)});
    return merge(left, right);
  }

 private:
  vector<vector<int>> merge(const vector<vector<int>>& left,
                            const vector<vector<int>>& right) {
    vector<vector<int>> ans;
    int i = 0;  // left's index
    int j = 0;  // right's index
    int leftY = 0;
    int rightY = 0;

    while (i < left.size() && j < right.size())
      // choose the point with smaller x
      if (left[i][0] < right[j][0]) {
        leftY = left[i][1];  // update the ongoing leftY
        addPoint(ans, left[i][0], max(left[i++][1], rightY));
      } else {
        rightY = right[j][1];  // update the ongoing rightY
        addPoint(ans, right[j][0], max(right[j++][1], leftY));
      }

    while (i < left.size())
      addPoint(ans, left[i][0], left[i++][1]);

    while (j < right.size())
      addPoint(ans, right[j][0], right[j++][1]);

    return ans;
  }

  void addPoint(vector<vector<int>>& ans, int x, int y) {
    if (!ans.empty() && ans.back()[0] == x) {
      ans.back()[1] = y;
      return;
    }
    if (!ans.empty() && ans.back()[1] == y)
      return;
    ans.push_back({x, y});
  }
};
