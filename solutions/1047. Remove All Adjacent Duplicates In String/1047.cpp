class Solution {
 public:
  string removeDuplicates(const string& S) {
    string ans;

    for (const char c : S)
      if (!ans.empty() && ans.back() == c)
        ans.pop_back();
      else
        ans.push_back(c);

    return ans;
  }
};
