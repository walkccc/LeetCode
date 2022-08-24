class Solution {
  public int minMeetingRooms(int[][] intervals) {
    final int n = intervals.length;
    int ans = 0;
    int[] starts = new int[n];
    int[] ends = new int[n];

    for (int i = 0; i < n; ++i) {
      starts[i] = intervals[i][0];
      ends[i] = intervals[i][1];
    }

    Arrays.sort(starts);
    Arrays.sort(ends);

    // j points to ends
    for (int i = 0, j = 0; i < n; ++i)
      if (starts[i] < ends[j])
        ++ans;
      else
        ++j;

    return ans;
  }
}
