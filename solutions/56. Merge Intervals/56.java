class Solution {
  public int[][] merge(int[][] intervals) {
    List<int[]> ans = new ArrayList<>();

    Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));

    for (int[] interval : intervals)
      if (ans.isEmpty() || ans.get(ans.size() - 1)[1] < interval[0])
        ans.add(interval);
      else
        ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], interval[1]);

    return ans.toArray(int[][] ::new);
  }
}
