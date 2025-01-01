class Solution {
 public:
  int maximumValue(vector<string>& strs) {
    int ans = 0;
    for (const string& s : strs)
      ans = max(ans, ranges::any_of(s, [](char c) { return isalpha(c); })
                         ? static_cast<int>(s.length())
                         : stoi(s));
    return ans;
  }
};
