class Solution {
  public int bulbSwitch(int n) {
    // k-th bulb only be switched when k % i == 0.
    // so we can reiterate the problem:
    // to find # of number <= n that have odd factors.
    // Obviously, only square numbers have odd factor(s).
    // e.g. n = 10, only 1, 4, and 9 are square numbers that <= 10
    return (int) Math.sqrt(n);
  }
}
