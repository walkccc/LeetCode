class Solution {
  public boolean reorderedPowerOf2(int N) {
    int count = counter(N);

    for (int i = 0; i < 30; ++i)
      if (counter(1 << i) == count)
        return true;

    return false;
  }

  private int counter(int n) {
    int count = 0;

    for (; n > 0; n /= 10)
      count += Math.pow(10, n % 10);

    return count;
  }
}
