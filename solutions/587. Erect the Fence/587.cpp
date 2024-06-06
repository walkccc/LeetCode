// Monotone Chain
class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    vector<vector<int>> hull;

    ranges::sort(trees, [](const vector<int>& a, const vector<int>& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    // Build the lower hull: left-to-right scan.
    for (const vector<int>& tree : trees) {
      while (hull.size() > 1 &&
             cross(hull.back(), hull[hull.size() - 2], tree) > 0)
        hull.pop_back();
      hull.push_back(tree);
    }
    hull.pop_back();

    // Build the upper hull: right-to-left scan.
    for (int i = trees.size() - 1; i >= 0; --i) {
      while (hull.size() > 1 &&
             cross(hull.back(), hull[hull.size() - 2], trees[i]) > 0)
        hull.pop_back();
      hull.push_back(trees[i]);
    }

    // Remove the redundant elements from the stack.
    ranges::sort(hull, [](const vector<int>& a, const vector<int>& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    hull.erase(unique(hull.begin(), hull.end(),
                      [](const vector<int>& a, const vector<int>& b) {
      return a[0] == b[0] && a[1] == b[1];
    }),
               hull.end());
    return hull;
  }

 private:
  int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
    return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
  }
};
