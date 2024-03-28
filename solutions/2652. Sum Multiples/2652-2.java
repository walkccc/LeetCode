public class Solution {
  public int sumOfMultiples(int n) {
    return sumOfMultiples(n, 3) + sumOfMultiples(n, 5) + sumOfMultiples(n, 7) -
        (sumOfMultiples(n, 15) + sumOfMultiples(n, 21) + sumOfMultiples(n, 35)) +
        sumOfMultiples(n, 105);
  }

  // Returns the sum of multiples of value in [1, n].
  private int sumOfMultiples(int n, int value) {
    final int lo = value;
    final int hi = n / value * value;
    final int count = (hi - lo) / value + 1;
    return (lo + hi) * count / 2;
  }
}
