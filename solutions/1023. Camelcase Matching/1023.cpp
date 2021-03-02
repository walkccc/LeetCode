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

    for (int i = 0; i < query.length(); ++i)
      if (j < pattern.length() && query[i] == pattern[j])
        ++j;
      else if (isupper(query[i]))
        return false;

    return j == pattern.length();
  }
};
