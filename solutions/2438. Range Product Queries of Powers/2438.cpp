class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMaxDigit = 30;
    vector<int> ans;
    vector<int> powers;

    for (int i = 0; i < kMaxDigit; ++i)
      if (n >> i & 1)
        powers.push_back(1 << i);

    for (const vector<int>& q : queries) {
      const int left = q[0];
      const int right = q[1];
      long prod = 1;
      for (int i = left; i <= right; ++i) {
        prod *= powers[i];
        prod %= kMod;
      }
      ans.push_back(prod);
    }

    return ans;
  }
};
