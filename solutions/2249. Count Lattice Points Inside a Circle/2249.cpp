class Solution {
 public:
  int countLatticePoints(vector<vector<int>>& circles) {
    int ans = 0;

    for (int x = 0; x < 201; ++x)
      for (int y = 0; y < 201; ++y)
        ans += any_of(begin(circles), end(circles), [&](const auto& c) {
          return (c[0] - x) * (c[0] - x) + (c[1] - y) * (c[1] - y) <=
                 c[2] * c[2];
        });

    return ans;
  }
};
