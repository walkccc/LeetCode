class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> ans;
    unordered_set<string_view> seen;
    const string_view sv(s);

    for (int i = 0; i + 10 <= s.length(); ++i) {
      if (seen.contains(sv.substr(i, 10)))
        ans.insert(s.substr(i, 10));
      seen.insert(sv.substr(i, 10));
    }

    return {ans.begin(), ans.end()};
  }
};
