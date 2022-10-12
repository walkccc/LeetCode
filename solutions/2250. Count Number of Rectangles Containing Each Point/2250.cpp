class Solution {
 public:
  vector<int> countRectangles(vector<vector<int>>& rectangles,
                              vector<vector<int>>& points) {
    vector<int> ans;
    vector<vector<int>> yToXs(101);

    for (const vector<int>& r : rectangles)
      yToXs[r[1]].push_back(r[0]);

    for (auto& xs : yToXs)
      sort(begin(xs), end(xs));

    for (const vector<int>& p : points) {
      int count = 0;
      for (int y = p[1]; y < 101; ++y) {
        const vector<int>& xs = yToXs[y];
        count += end(xs) - lower_bound(begin(xs), end(xs), p[0]);
      }
      ans.push_back(count);
    }

    return ans;
  }
};
