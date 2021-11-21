class Solution {
  public int videoStitching(int[][] clips, int T) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    Arrays.sort(clips, (a, b) -> a[0] - b[0]);

    int i = 0;
    while (farthest < T) {
      while (i < clips.length && clips[i][0] <= end)
        farthest = Math.max(farthest, clips[i++][1]);
      if (end == farthest)
        return -1;
      ++ans;
      end = farthest;
    }

    return ans;
  }
}
