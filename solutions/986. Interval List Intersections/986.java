class Solution {
  public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
    List<int[]> ans = new ArrayList<>();
    short i = 0;
    short j = 0;

    while (i < firstList.length && j < secondList.length) {
      // lo := the start of the intersection
      // hi := the end of the intersection
      final int lo = Math.max(firstList[i][0], secondList[j][0]);
      final int hi = Math.min(firstList[i][1], secondList[j][1]);
      if (lo <= hi)
        ans.add(new int[] {lo, hi});
      if (firstList[i][1] < secondList[j][1])
        ++i;
      else
        ++j;
    }

    return ans.toArray(new int[ans.size()][]);
  }
}
