class Solution {
 public:
  string minimumString(string a, string b, string c) {
    const string abc = merge(a, merge(b, c));
    const string acb = merge(a, merge(c, b));
    const string bac = merge(b, merge(a, c));
    const string bca = merge(b, merge(c, a));
    const string cab = merge(c, merge(a, b));
    const string cba = merge(c, merge(b, a));
    return getMin({abc, acb, bac, bca, cab, cba});
  }

 private:
  // Merges a and b.
  string merge(const string& a, const string& b) {
    if (b.find(a) != string::npos)  // a is a substring of b.
      return b;
    for (int i = 0; i < a.length(); ++i) {
      const string aSuffix = a.substr(i);
      const string bPrefix = b.substr(0, min(b.length(), aSuffix.length()));
      if (aSuffix == bPrefix)
        return a + b.substr(bPrefix.length());
    }
    return a + b;
  }

  // Returns the lexicographically smallest string.
  string getMin(const vector<string>& words) {
    string res = words[0];
    for (int i = 1; i < words.size(); ++i)
      res = getMin(res, words[i]);
    return res;
  }

  // Returns the lexicographically smaller string.
  string getMin(const string& a, const string& b) {
    return (a.length() < b.length() || (a.length() == b.length() && a < b)) ? a
                                                                            : b;
  }
};
