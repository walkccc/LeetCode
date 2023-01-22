class Solution {
  public int maxSatisfied(int[] customers, int[] grumpy, int X) {
    int satisfied = 0;
    int madeSatisfied = 0;
    int windowSatisfied = 0;

    for (int i = 0; i < customers.length; ++i) {
      if (grumpy[i] == 0)
        satisfied += customers[i];
      else
        windowSatisfied += customers[i];
      if (i >= X && grumpy[i - X] == 1)
        windowSatisfied -= customers[i - X];
      madeSatisfied = Math.max(madeSatisfied, windowSatisfied);
    }

    return satisfied + madeSatisfied;
  }
}
