class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    long ans = 0;
    int y = x;

    while (y) {
      ans = ans * 10 + y % 10;
      y /= 10;
    }

    return ans == x;
  }
};