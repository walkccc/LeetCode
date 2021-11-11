class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points,
                          vector<vector<int>>& queries) {
    vector<int> ans;

    auto squared = [](int x) { return x * x; };

    for (const auto& q : queries) {
      const int rSquared = q[2] * q[2];
      int count = 0;
      for (const auto& p : points)
        count += squared(p[0] - q[0]) + squared(p[1] - q[1]) <= rSquared;
      ans.push_back(count);
    }

    return ans;
  }
};
