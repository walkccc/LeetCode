class Solution {
  public int findIntegers(int num) {
    StringBuilder bits = new StringBuilder();
    for (; num > 0; num >>= 1)
      bits.append(num & 1);

    final int n = bits.length();
    int[] zero = new int[n];
    int[] one = new int[n];

    zero[0] = 1;
    one[0] = 1;

    for (int i = 1; i < n; ++i) {
      zero[i] = zero[i - 1] + one[i - 1];
      one[i] = zero[i - 1];
    }

    int ans = zero[n - 1] + one[n - 1];

    for (int i = n - 2; i >= 0; --i) {
      // numbers greater than num and <= 2^n - 1 are invalid
      if (bits.charAt(i) == '1' && bits.charAt(i + 1) == '1')
        break;
      if (bits.charAt(i) == '0' && bits.charAt(i + 1) == '0')
        ans -= one[i];
    }

    return ans;
  }
}
