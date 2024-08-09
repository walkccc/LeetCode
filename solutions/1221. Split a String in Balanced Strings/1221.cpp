class Solution {
 public:
  int balancedStringSplit(string s) {
    int ans = 0;
    int count = 0;

    for (const char c : s) {
      count += c == 'L' ? 1 : -1;
      if (count == 0)
        ++ans;
    }

    return ans;
  }
};
