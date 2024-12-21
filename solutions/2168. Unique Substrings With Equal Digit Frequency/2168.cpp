class Solution {
 public:
  int equalDigitFrequency(string s) {
    vector<vector<int>> counts;  // counts[i] := the counter map of s[0..i]
    vector<int> count(10);
    vector<long> pows{1};  // pows[i] := kBase^i % kHash
    // hash[i] = the hash of the first i letters of s, where hash[i] =
    // (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % kHash
    vector<long> hash{0};
    unordered_set<int> seen;

    for (const char c : s) {
      ++count[c - '0'];
      counts.push_back(count);
      pows.push_back(pows.back() * kBase % kHash);
      hash.push_back((hash.back() * kBase + val(c)) % kHash);
    }

    for (int i = 0; i < s.length(); ++i)
      for (int j = i; j < s.length(); ++j)
        if (isSameFreq(counts, i, j))
          seen.insert(getRollingHash(i, j + 1, hash, pows));

    return seen.size();
  }

 private:
  static constexpr int kMax = 1001;
  static constexpr int kBase = 11;
  static constexpr int kHash = 1'000'000'007;

  static constexpr int val(char c) {
    return c - '0' + 1;
  }

  // Returns true if s[i..j] has the same digit frequency.j
  bool isSameFreq(const vector<vector<int>>& counts, int i, int j) {
    vector<int> count = counts[j];
    if (i > 0)
      for (int num = 0; num < 10; ++num)
        count[num] -= counts[i - 1][num];
    return equalFreq(count);
  }

  bool equalFreq(const vector<int>& count) {
    int minfreq = kMax;
    int maxfreq = 0;
    for (const int freq : count)
      if (freq > 0) {
        minfreq = min(minfreq, freq);
        maxfreq = max(maxfreq, freq);
      }
    return minfreq == maxfreq;
  }

  // Returns the rolling hash of s[l..r).
  int getRollingHash(int l, int r, const vector<long>& hash,
                     const vector<long>& pows) {
    const long h = (hash[r] - hash[l] * pows[r - l]) % kHash;
    return h < 0 ? h + kHash : h;
  }
};
