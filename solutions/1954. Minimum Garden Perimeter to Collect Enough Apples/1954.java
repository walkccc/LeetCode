class Solution {
  public long minimumPerimeter(long neededApples) {
    long l = 1;
    long r = 100_000; // \sqrt [3] {10^{15}}

    while (l < r) {
      final long m = (l + r) / 2;
      if (numApples(m) >= neededApples)
        r = m;
      else
        l = m + 1;
    }

    return l * 8;
  }

  // Returns the number of apples at the k-th level.
  //    k := the level making perimeter = 8k
  // p(k) := the number of apples at the k-th level on the perimeter
  // n(k) := the number of apples at the k-th level not no the perimeter
  //
  // p(1) =             1 + 2
  // p(2) =         3 + 2 + 3 + 4
  // p(3) =     5 + 4 + 3 + 4 + 5 + 6
  // p(4) = 7 + 6 + 5 + 4 + 5 + 6 + 7 + 8
  // p(k) = k + 2(k+1) + 2(k+2) + ... + 2(k+k-1) + 2k
  //      = k + 2k^2 + 2k(k-1)/2
  //      = k + 2k^2 + k^2 - k = 3k^2
  //
  // n(k) = p(1) + p(2) + p(3) + ... + p(k)
  //      = 31  + 34  + 39  + ... + 3k^2
  //      = 3 * (1 + 4 + 9 + ... + k^2)
  //      = 3 * k(k+1)(2k+1)/6 = k(k+1)(2k+1)/2
  // So, the number of apples at the k-th level should be
  //   k(k+1)(2k+1)/2 * 4 = 2k(k+1)(2k+1)
  private long numApples(long k) {
    return 2L * k * (k + 1) * (2 * k + 1);
  }
}
