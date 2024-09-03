class Solution {
  public int[] getNoZeroIntegers(int n) {
    for (int A = 1; A < n; ++A) {
      int B = n - A;
      if (!String.valueOf(A).contains("0") && !String.valueOf(B).contains("0"))
        return new int[] {A, B};
    }

    throw new IllegalArgumentException();
  }
}
