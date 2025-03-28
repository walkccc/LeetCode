class Solution {
  public int subsequenceCount(int[] nums) {
    final int MOD = 1_000_000_007;
    int even = 0; // the number of subsequences with even sum
    int odd = 0;  // the number of subsequences with odd sum

    for (final int num : nums)
      if (num % 2 == 0) {
        // Appending an even number to a subsequence doesn't change the parity.
        // The even number itself is also a valid subsequence.
        even = (even + even + 1) % MOD;
        odd = (odd + odd) % MOD;
      } else {
        // Appending an odd number to a subsequence changes the parity.
        // The odd number itself is also a valid subsequence.
        final int newEven = (even + odd) % MOD;
        odd = (odd + even + 1) % MOD;
        even = newEven;
      }

    return odd % MOD;
  }
}
