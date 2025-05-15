class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMaxBit = 30;
    vector<int> ans;
    vector<int> pows;

    for (int i = 0; i < kMaxBit; ++i)
      if (n >> i & 1)
        pows.push_back(1 << i);

    for (const vector<int>& query : queries) {
      const int left = query[0];
      const int right = query[1];
      long prod = 1;
      for (int i = left; i <= right; ++i) {
        prod *= pows[i];
        prod %= kMod;
      }
      ans.push_back(prod);
    }

    return ans;
  }
};
