class Solution {
  public int brightestPosition(int[][] lights) {
    int ans = Integer.MAX_VALUE;
    int maxBrightness = -1;
    int currBrightness = 0;
    Map<Integer, Integer> timeline = new TreeMap<>();

    for (int[] light : lights) {
      final int position = light[0];
      final int range = light[1];
      final int start = position - range;
      final int end = position + range + 1;
      timeline.merge(start, 1, Integer::sum);
      timeline.merge(end, -1, Integer::sum);
    }

    for (final int pos : timeline.keySet()) {
      final int brightness = timeline.get(pos);
      currBrightness += brightness;
      if (currBrightness > maxBrightness) {
        maxBrightness = currBrightness;
        ans = pos;
      }
    }

    return ans;
  }
}
