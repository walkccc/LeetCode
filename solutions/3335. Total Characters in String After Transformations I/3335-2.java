class Solution {
  public int lengthAfterTransformations(String s, int t) {
    // T[i][j] := the number of ways to transform ('a' + i) to ('a' + j)
    int[][] T = getTransformationMatrix();
    int[][] poweredT = matrixPow(T, t);
    int[] count = new int[26];
    // lengths[i] := the total length of ('a' + i) after t transformations
    long[] lengths = new long[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) {
        lengths[j] += (long) count[i] * poweredT[i][j];
        lengths[j] %= MOD;
      }

    return (int) (Arrays.stream(lengths).sum() % MOD);
  }

  private static final int MOD = 1_000_000_007;

  private int[][] getTransformationMatrix() {
    int[][] T = new int[26][26];
    // 'z' -> 'ab'
    T[25][0] = 1;
    T[25][1] = 1;
    // 'a' -> 'b', 'b' -> 'c', ..., 'y' -> 'z'
    for (int i = 0; i < 25; ++i)
      T[i][i + 1] = 1;
    return T;
  }

  private int[][] getIdentityMatrix(int sz) {
    int[][] I = new int[sz][sz];
    for (int i = 0; i < sz; ++i)
      I[i][i] = 1;
    return I;
  }

  // Returns A * B.
  private int[][] matrixMult(int[][] A, int[][] B) {
    final int sz = A.length;
    int[][] C = new int[sz][sz];
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k)
          C[i][j] = (int) ((C[i][j] + (long) A[i][k] * B[k][j]) % MOD);
    return C;
  }

  // Returns M^n.
  private int[][] matrixPow(int[][] M, int n) {
    if (n == 0)
      return getIdentityMatrix(M.length);
    if (n % 2 == 1)
      return matrixMult(M, matrixPow(M, n - 1));
    return matrixPow(matrixMult(M, M), n / 2);
  }
}
