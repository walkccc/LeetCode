class Solution {
  public int[] decrypt(int[] code, int k) {
    final int n = code.length;
    int[] ans = new int[n];
    if (k == 0)
      return ans;

    int sum = 0;
    int start = k > 0 ? 1 : n + k; // the start of the next k numbers
    int end = k > 0 ? k : n - 1;   // the end of the next k numbers

    for (int i = start; i <= end; ++i)
      sum += code[i];

    for (int i = 0; i < n; ++i) {
      ans[i] = sum;
      sum -= code[start++ % n];
      sum += code[++end % n];
    }

    return ans;
  }
}
