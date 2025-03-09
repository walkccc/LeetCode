class Solution {
 public:
  long long minEnd(int n, int x) {
    // Set x's 0s with (n - 1)'s LSb-to-MSb bits, preserving x's 1s. This
    // operation increase x for (n - 1) iterations while preserving x's 1s.
    const int kMaxBit = log2(n) + log2(x) + 2;
    const long k = n - 1;
    long ans = x;
    int kBinaryIndex = 0;

    for (int i = 0; i < kMaxBit; ++i) {
      if ((ans >> i & 1) == 0) {
        // Set x's 0 with k's bit if the running bit of k is 1.
        if (k >> kBinaryIndex & 1)
          ans |= 1L << i;
        ++kBinaryIndex;
      }
    }

    return ans;
  }
};
