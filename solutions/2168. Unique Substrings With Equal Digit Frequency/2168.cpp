class Solution {
 public:
  int equalDigitFrequency(string s) {
    const string_view sv(s);
    unordered_set<int> seen;

    for (int i = 0; i < s.length(); ++i)
      for (int j = i; j < s.length(); ++j)
        if (isUnique(sv.substr(i, j - i + 1)))
          seen.insert(getRollingHash(sv.substr(i, j - i + 1)));

    return seen.size();
  }

 private:
  static constexpr int power = 11;
  static constexpr int kMod = 1'000'000'007;

  bool isUnique(const string_view& sv) {
    vector<int> count(10);
    int unique = 0;
    for (const char c : sv)
      if (++count[c - '0'] == 1)
        ++unique;
    const int maxCount = ranges::max(count);
    return maxCount * unique == sv.length();
  }

  int getRollingHash(const string_view& sv) {
    long hash = 0;
    for (const char c : sv)
      hash = (hash * power + val(c)) % kMod;
    return hash;
  }

  constexpr int val(char c) {
    return c - '0' + 1;
  }
};
