class Solution {
  public boolean isSameAfterReversals(int num) {
    final int reversed1 = getReversed(num);
    final int reversed2 = getReversed(reversed1);
    return reversed2 == num;
  }

  private int getReversed(int num) {
    int reversed = 0;
    while (num > 0) {
      reversed = reversed * 10 + num % 10;
      num /= 10;
    }
    return reversed;
  }
}
