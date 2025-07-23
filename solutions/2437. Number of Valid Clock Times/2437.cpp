class Solution {
 public:
  int countTime(string time) {
    int ans = 1;
    if (time[3] == '?')
      ans *= 6;
    if (time[4] == '?')
      ans *= 10;

    if (time[0] == '?' && time[1] == '?')
      return ans * 24;
    if (time[0] == '?')
      return time[1] < '4' ? ans * 3 : ans * 2;
    if (time[1] == '?')
      return time[0] == '2' ? ans * 4 : ans * 10;
    return ans;
  }
};
