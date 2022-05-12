class Solution {
 public:
  string splitLoopedString(vector<string>& strs) {
    string ans;
    vector<string> sortedStrs;

    for (const auto& s : strs)
      sortedStrs.push_back(max(s, {rbegin(s), rend(s)}));

    for (int i = 0; i < sortedStrs.size(); ++i)
      for (const auto& s :
           {sortedStrs[i], {rbegin(sortedStrs[i]), rend(sortedStrs[i])}})
        for (int j = 0; j <= s.length(); ++j)
          ans = max(ans, s.substr(j) + join(sortedStrs, i) + s.substr(0, j));

    return ans;
  }

 private:
  string reversed(const string& s) {
    string r = s;
    reverse(begin(r), end(r));
    return r;
  }

  string join(const vector<string>& sortedStrs, int i) {
    string joined;
    for (int j = i + 1; j < sortedStrs.size(); ++j)
      joined += sortedStrs[j];
    for (int j = 0; j < i; ++j)
      joined += sortedStrs[j];
    return joined;
  }
};
