class Solution {
  public boolean isIdealPermutation(int[] A) {
    for (int i = 0; i < A.length; ++i)
      if (Math.abs(A[i] - i) > 1)
        return false;
    return true;
  }
}
