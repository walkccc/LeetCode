class Solution {
 public:
  long long findKthSmallest(vector<int>& coins, int k) {
    const vector<vector<long long>> sizeToLcms = getSizeToLcms(coins);
    long long l = 0;
    long long r = 1LL * k * ranges::min(coins);

    while (l < r) {
      const long long m = (l + r) / 2;
      if (numDenominationsNoGreaterThan(sizeToLcms, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns the number of denominations <= m.
  long long numDenominationsNoGreaterThan(
      const vector<vector<long long>>& sizeToLcms, long long m) {
    long long res = 0;
    for (int sz = 1; sz < sizeToLcms.size(); ++sz)
      for (const long long lcm : sizeToLcms[sz])
        // Principle of Inclusion-Exclusion (PIE)
        res += m / lcm * pow(-1, sz + 1);
    return res;
  };

  // Returns the LCMs for each number of combination of coins.
  vector<vector<long long>> getSizeToLcms(const vector<int>& coins) {
    const int n = coins.size();
    const int maxMask = 1 << n;
    vector<vector<long long>> sizeToLcms(n + 1);

    for (int mask = 1; mask < maxMask; ++mask) {
      long long lcmOfSelectedCoins = 1;
      for (int i = 0; i < n; ++i)
        if (mask >> i & 1)
          lcmOfSelectedCoins = lcm(lcmOfSelectedCoins, coins[i]);
      sizeToLcms[__builtin_popcount(mask)].push_back(lcmOfSelectedCoins);
    }

    return sizeToLcms;
  }
};
