class Solution {
 public:
  int minimumChairs(string s) {
    int ans = 0;
    int chairs = 0;

    for (const char c : s) {
      chairs += c == 'E' ? 1 : -1;
      ans = max(ans, chairs);
    }

    return ans;
  }
};
