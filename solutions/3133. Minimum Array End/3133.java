class Solution {
  public long minEnd(int n, int x) {
    // Set x's 0s with (n - 1)'s LSb-to-MSb bits, preserving x's 1s. This
    // operation increase x for (n - 1) iterations while preserving x's 1s.
    final int MAX_BIT = bitLength(n) + bitLength(x);
    final long k = n - 1;
    long ans = x;
    int BINARY_INDEX = 0;

    for (int i = 0; i < MAX_BIT; ++i) {
      if ((ans >> i & 1) == 0) {
        // Set x's 0 with k's bit if the running bit of k is 1.
        if ((k >> BINARY_INDEX & 1) == 1)
          ans |= 1L << i;
        ++BINARY_INDEX;
      }
    }

    return ans;
  }

  private int bitLength(int n) {
    return 32 - Integer.numberOfLeadingZeros(n);
  }
}
