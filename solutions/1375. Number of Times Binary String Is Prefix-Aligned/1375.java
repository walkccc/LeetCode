class Solution {
  public int numTimesAllBlue(int[] flips) {
    int ans = 0;
    int rightmost = 0;

    for (int i = 0; i < flips.length; ++i) {
      rightmost = Math.max(rightmost, flips[i]);
      // Math.max(flips[0..i]) = rightmost = i + 1,
      // so flips[0..i] is a permutation of 1, 2, ..., i + 1.
      if (rightmost == i + 1)
        ++ans;
    }

    return ans;
  }
}
