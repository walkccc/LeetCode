class Solution {
 public:
  int countKSubsequencesWithMaxBeauty(string s, int k) {
    unordered_map<char, int> count;
    for (const char c : s)
      ++count[c];
    if (count.size() < k)
      return 0;

    long ans = 1;

    for (const auto& [fc, numOfChars] : getFreqCountPairs(count)) {
      if (numOfChars >= k) {
        ans *= nCk(numOfChars, k);
        ans %= kMod;
        return ans * modPow(fc, k) % kMod;
      }
      ans *= modPow(fc, numOfChars);
      ans %= kMod;
      k -= numOfChars;
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  vector<pair<int, int>> getFreqCountPairs(
      const unordered_map<char, int>& count) {
    unordered_map<int, int> freqCount;
    for (const auto& [_, value] : count)
      ++freqCount[value];
    vector<pair<int, int>> freqCountPairs;
    for (const auto& [fc, numOfChars] : freqCount)
      freqCountPairs.emplace_back(fc, numOfChars);
    ranges::sort(freqCountPairs, ranges::greater{},
                 [](const pair<int, int>& freqCountPair) {
      return freqCountPair.first;
    });
    return freqCountPairs;
  }

  long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      res = res * (n - i + 1) / i;
    return res;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
