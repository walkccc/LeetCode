class Solution {
 public:
  string longestDupSubstring(string s) {
    const int n = s.length();
    vector<int> pows(n, 1);
    int bestStart = -1;
    int l = 1;
    int r = n;

    for (int i = 1; i < n; ++i)
      pows[i] = pows[i - 1] * kBase % kHash;

    while (l < r) {
      const int m = (l + r) / 2;
      const int start = getStart(s, m, pows);
      if (start == -1) {
        r = m;
      } else {
        bestStart = start;
        l = m + 1;
      }
    }

    if (bestStart == -1)
      return "";
    if (getStart(s, l, pows) == -1)
      return s.substr(bestStart, l - 1);
    return s.substr(bestStart, l);
  }

 private:
  static constexpr long kBase = 26;
  static constexpr int kHash = 1'000'000'007;

  static constexpr int val(char c) {
    return c - 'a';
  }

  // k := the length of the substring to be hashed
  int getStart(const string& s, int k, const vector<int>& pows) {
    unordered_map<int, vector<int>> hashToStarts;
    long h = 0;

    // Compute the hash value of s[:k].
    for (int i = 0; i < k; ++i)
      h = (h * kBase % kHash + val(s[i])) % kHash;
    hashToStarts[h].push_back(0);

    // Compute the rolling hash by Rabin Karp.
    for (int i = k; i < s.length(); ++i) {
      const int startIndex = i - k + 1;
      h = ((h - static_cast<long>(pows[k - 1]) * val(s[i - k])) % kHash +
           kHash) %
          kHash;
      h = (h * kBase + val(s[i])) % kHash;
      if (const auto it = hashToStarts.find(h); it != hashToStarts.cend()) {
        const string currSub = s.substr(startIndex, k);
        for (const int start : it->second)
          if (s.substr(start, k) == currSub)
            return startIndex;
      }
      hashToStarts[h].push_back(startIndex);
    }

    return -1;
  }
};
