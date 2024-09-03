class Solution {
 public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    const string a = to_string(start);
    const string b = to_string(finish);
    const string aWithLeadingZeros = string(b.length() - a.length(), '0') + a;
    vector<vector<vector<long>>> mem(
        b.length(), vector<vector<long>>(2, vector<long>(2, -1)));
    const string sWithLeadingZeros = string(b.length() - s.length(), '0') + s;
    return count(aWithLeadingZeros, b, 0, limit, s, true, true, mem);
  }

 private:
  // Returns the number of powerful integers, considering the i-th digit, where
  // `isTight1` indicates if the current digit is tightly bound for `a` and
  // `isTight2` indicates if the current digit is tightly bound for `b`.
  long count(const string& a, const string& b, int i, int limit,
             const string& s, bool isTight1, bool isTight2,
             vector<vector<vector<long>>>& mem) {
    if (i + s.length() == b.length()) {
      const string aMinSuffix = isTight1
                                    ? std::string(a.end() - s.length(), a.end())
                                    : string(s.length(), '0');
      const string bMaxSuffix = isTight2
                                    ? std::string(b.end() - s.length(), b.end())
                                    : string(s.length(), '9');
      const long suffix = stoll(s);
      return stoll(aMinSuffix) <= suffix && suffix <= stoll(bMaxSuffix);
    }

    if (mem[i][isTight1][isTight2] != -1)
      return mem[i][isTight1][isTight2];

    long res = 0;
    const int minDigit = isTight1 ? a[i] - '0' : 0;
    const int maxDigit = isTight2 ? b[i] - '0' : 9;

    for (int d = minDigit; d <= maxDigit; ++d) {
      if (d > limit)
        continue;
      const bool nextIsTight1 = isTight1 && (d == minDigit);
      const bool nextIsTight2 = isTight2 && (d == maxDigit);
      res += count(a, b, i + 1, limit, s, nextIsTight1, nextIsTight2, mem);
    }

    return mem[i][isTight1][isTight2] = res;
  }
};
