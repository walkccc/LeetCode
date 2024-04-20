class Solution {
  public int findTheWinner(int n, int k) {
    // Converts back to 1-indexed.
    return f(n, k) + 1;
  }

  // e.g. n = 4, k = 2.
  // By using 0-indexed notation, we have the following circle:
  //
  // 0 -> 1 -> 2 -> 3 -> 0
  //      x
  //           0 -> 1 -> 2 -> 0
  //
  // After the first round, 1 is removed.
  // So, 2 becomes 0, 3 becomes 1, and 0 becomes 2.
  // Let's denote that oldIndex = f(n, k) and newIndex = f(n - 1, k).
  // By observation, we know f(n, k) = (f(n - 1, k) + k) % n.
  private int f(int n, int k) {
    if (n == 1)
      return 0;
    return (f(n - 1, k) + k) % n;
  }
}
