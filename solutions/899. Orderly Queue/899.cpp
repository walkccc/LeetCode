class Solution {
 public:
  string orderlyQueue(string s, int k) {
    if (k > 1) {
      ranges::sort(s);
      return s;
    }

    string ans = s;

    for (int i = 1; i < s.length(); ++i)
      ans = min(ans, s.substr(i) + s.substr(0, i));

    return ans;
  }
};
