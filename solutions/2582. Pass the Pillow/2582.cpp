class Solution {
 public:
  int passThePillow(int n, int time) {
    // Repeat every (n - 1) * 2 seconds.
    time %= (n - 1) * 2;
    if (time < n)  // Going forward from 1.
      return 1 + time;
    return n - (time - (n - 1));  // Going backward from n.
  }
};
