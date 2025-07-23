class Solution {
  public boolean isBalanced(String num) {
    int balance = 0;
    int sign = 1;

    for (final char c : num.toCharArray()) {
      balance += sign * (c - '0');
      sign *= -1;
    }

    return balance == 0;
  }
}
