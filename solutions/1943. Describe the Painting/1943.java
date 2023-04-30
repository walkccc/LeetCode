class Solution {
  public List<List<Long>> splitPainting(int[][] segments) {
    List<List<Long>> ans = new ArrayList<>();
    int prevIndex = 0;
    long runningMix = 0;
    TreeMap<Integer, Long> timeline = new TreeMap<>();

    for (int[] segment : segments) {
      final int start = segment[0];
      final int end = segment[1];
      final int color = segment[2];
      timeline.merge(start, (long) color, Long::sum);
      timeline.merge(end, (long) -color, Long::sum);
    }

    for (final int i : timeline.keySet()) {
      final long mix = timeline.get(i);
      if (runningMix > 0)
        ans.add(List.of((long) prevIndex, (long) i, runningMix));
      runningMix += mix;
      prevIndex = i;
    }

    return ans;
  }
}
