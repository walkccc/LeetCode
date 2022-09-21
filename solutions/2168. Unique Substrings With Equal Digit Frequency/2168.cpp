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
  constexpr static int power = 11;
  constexpr static int kMod = 1'000'000'007;

  bool isUnique(const string_view& sv) {
    vector<int> count(10);
    int unique = 0;
    for (const char c : sv)
      if (++count[c - '0'] == 1)
        ++unique;
    const int maxCount = *max_element(begin(count), end(count));
    return maxCount * unique == sv.length();
  }

  int getRollingHash(const string_view& sv) {
    long hashed = 0;
    for (const char c : sv)
      hashed = (hashed * power + val(c)) % kMod;
    return hashed;
  }

  int val(char c) {
    return c - '0' + 1;
  }
};
