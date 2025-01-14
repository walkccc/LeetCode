class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    int ans = 0;
    vector<int> xs;

    for (const vector<int>& point : points) {
      const int x = point[0];
      xs.push_back(x);
    }

    ranges::sort(xs);

    for (int i = 1; i < xs.size(); ++i)
      ans = max(ans, xs[i] - xs[i - 1]);

    return ans;
  }
};
