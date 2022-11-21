class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;

    for (const string& q : queries)
      ans.push_back(isMatch(q, pattern));

    return ans;
  }

 private:
  bool isMatch(const string& q, const string& pattern) {
    int j = 0;

    for (int i = 0; i < q.length(); ++i)
      if (j < pattern.length() && q[i] == pattern[j])
        ++j;
      else if (isupper(q[i]))
        return false;

    return j == pattern.length();
  }
};
