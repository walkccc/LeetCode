class Solution {
 public:
  bool findGameWinner(int n) {
    return n % 6 != 1;
  }
};
