class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    for (int sz = min(str1.length(), str2.length()); sz > 0; --sz)
      if (isDivisible(str1, str2, sz))
        return str1.substr(0, sz);
    return "";
  }

 private:
  // Returns true if str1 and str2 are divisible by str1[0..sz).
  bool isDivisible(const string& str1, const string& str2, int sz) {
    if (str1.length() % sz > 0 || str2.length() % sz > 0)
      return false;
    const string gcd = str1.substr(0, sz);
    return str1 == repeat(gcd, str1.length() / sz) &&
           str2 == repeat(gcd, str2.length() / sz);
  }

  string repeat(const string& s, int n) {
    string res;
    for (int i = 0; i < n; ++i)
      res += s;
    return res;
  }
};
