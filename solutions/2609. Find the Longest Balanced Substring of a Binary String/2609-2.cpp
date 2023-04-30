class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0;
    int count0 = 0;
    int count1 = 0;

    for (const char c : s) {
      if (c == '0') {
        count0 = count1 > 0 ? 1 : count0 + 1;
        count1 = 0;
      } else {  // c == '1'
        ++count1;
      }
      if (count0 >= count1)
        ans = max(ans, count1);
    }

    return ans * 2;
  }
};
