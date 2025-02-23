class Solution {
 public:
  vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    const int maxNum = ranges::max(nums);
    vector<int> ans;
    // countDivisor[d] := the number of `nums` having `num % d == 0`
    vector<int> countDivisor(maxNum + 1);
    // countGcdPair[g] := the number of pairs having gcd == g
    vector<long> countGcdPair(maxNum + 1);
    // prefixCountGcdPair[g] := the number of pairs having gcd <= g
    vector<long> prefixCountGcdPair{0};

    for (const int num : nums)
      for (int i = 1; i * i <= num; ++i)
        if (num % i == 0) {
          ++countDivisor[i];
          if (i != num / i)
            ++countDivisor[num / i];
        }

    for (int gcd = maxNum; gcd >= 1; --gcd) {
      // There are C(countDivisor[gcd], 2) pairs that have a common divisor
      // that's a multiple of `gcd` (including the one that equals to `gcd`).
      // So, substract the multiples of `gcd` to have the number of pairs with a
      // gcd that's exactly `gcd`.
      countGcdPair[gcd] =
          countDivisor[gcd] * static_cast<long>(countDivisor[gcd] - 1) / 2;
      for (int largerGcd = 2 * gcd; largerGcd <= maxNum; largerGcd += gcd)
        countGcdPair[gcd] -= countGcdPair[largerGcd];
    }

    for (int gcd = 1; gcd <= maxNum; ++gcd)
      prefixCountGcdPair.push_back(prefixCountGcdPair.back() +
                                   countGcdPair[gcd]);

    for (const long query : queries)
      ans.push_back(getNthGcdPair(query, prefixCountGcdPair));

    return ans;
  }

 private:
  // Returns the `query`-th gcd pair.
  int getNthGcdPair(long query, const vector<long>& prefixCountGcdPair) {
    int l = 1;
    int r = prefixCountGcdPair.size() - 1;
    while (l < r) {
      const int m = (l + r) / 2;
      if (prefixCountGcdPair[m] < query + 1)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};
