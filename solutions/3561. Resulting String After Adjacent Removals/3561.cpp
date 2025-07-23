class Solution {
 public:
  string resultingString(string s) {
    string ans;

    for (const char c : s)
      if (!ans.empty() &&
          (abs(ans.back() - c) == 1 || abs(ans.back() - c) == 25))
        ans.pop_back();
      else
        ans += c;

    return ans;
  }
};
