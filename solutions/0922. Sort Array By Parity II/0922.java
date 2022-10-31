class Solution {
  public int[] sortArrayByParityII(int[] A) {
    final int n = A.length;

    for (int i = 0, j = 1; i < n; i += 2, j += 2) {
      while (i < n && A[i] % 2 == 0)
        i += 2;
      while (j < n && A[j] % 2 == 1)
        j += 2;
      if (i < n) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    }

    return A;
  }
}
