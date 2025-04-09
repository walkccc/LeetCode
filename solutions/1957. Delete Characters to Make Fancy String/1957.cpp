class Solution {
 public:
  string makeFancyString(string s) {
    string ans;
    for (const char c : s)
      if (ans.length() < 2 || ans.back() != c || ans[ans.size() - 2] != c)
        ans.push_back(c);
    return ans;
  }
};
