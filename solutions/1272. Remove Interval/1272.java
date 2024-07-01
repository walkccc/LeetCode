class Solution {
  public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
    List<List<Integer>> ans = new ArrayList<>();

    for (int[] interval : intervals) {
      final int a = interval[0];
      final int b = interval[1];
      if (a >= toBeRemoved[1] || b <= toBeRemoved[0]) {
        ans.add(Arrays.asList(a, b));
      } else { // a < toBeRemoved[1] && b > toBeRemoved[0]
        if (a < toBeRemoved[0])
          ans.add(Arrays.asList(a, toBeRemoved[0]));
        if (b > toBeRemoved[1])
          ans.add(Arrays.asList(toBeRemoved[1], b));
      }
    }

    return ans;
  }
}
