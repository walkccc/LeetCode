class Solution {
  public int[][] merge(int[][] intervals) {
    List<int[]> ans = new ArrayList<>();

    Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

    for (int[] interval : intervals)
      if (ans.isEmpty() || ans.get(ans.size() - 1)[1] < interval[0])
        ans.add(interval);
      else
        ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], interval[1]);

    return ans.toArray(int[][] ::new);
  }
}
