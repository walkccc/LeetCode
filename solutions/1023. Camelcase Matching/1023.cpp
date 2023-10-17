class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    for (const string& query : queries)
      ans.push_back(isMatch(query, pattern));
    return ans;
  }

 private:
  bool isMatch(const string& query, const string& pattern) {
    int j = 0;
    for (const char c : query)
      if (j < pattern.length() && c == pattern[j])
        ++j;
      else if (isupper(c))
        return false;
    return j == pattern.length();
  }
};
