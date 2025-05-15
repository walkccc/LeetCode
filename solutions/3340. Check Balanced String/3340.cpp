class Solution {
 public:
  bool isBalanced(string num) {
    int balance = 0;
    int sign = 1;

    for (const char c : num) {
      balance += sign * (c - '0');
      sign *= -1;
    }

    return balance == 0;
  }
};
