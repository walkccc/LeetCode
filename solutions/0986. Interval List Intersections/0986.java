class Solution {
  public int[][] intervalIntersection(int[][] A, int[][] B) {
    List<int[]> ans = new ArrayList<>();
    short i = 0;
    short j = 0;

    while (i < A.length && j < B.length) {
      final int maxL = Math.max(A[i][0], B[j][0]);
      final int minR = Math.min(A[i][1], B[j][1]);
      if (maxL <= minR)
        ans.add(new int[] {maxL, minR});
      if (A[i][1] < B[j][1])
        ++i;
      else
        ++j;
    }

    return ans.toArray(new int[ans.size()][]);
  }
}
