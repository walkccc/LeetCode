class Solution {
 public:
  string removeStars(string s) {
    string ans;
    for (const char c : s)
      if (c == '*')
        ans.pop_back();
      else
        ans.push_back(c);
    return ans;
  }
};
