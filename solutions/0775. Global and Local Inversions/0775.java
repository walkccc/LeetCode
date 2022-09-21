class Solution {
  public boolean isIdealPermutation(int[] A) {
    int max = -1; // the most likely to be greater than A[i + 2]

    for (int i = 0; i + 2 < A.length; ++i) {
      max = Math.max(max, A[i]);
      if (max > A[i + 2])
        return false;
    }

    return true;
  }
}
