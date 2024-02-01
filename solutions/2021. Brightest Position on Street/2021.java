class Solution {
  public int brightestPosition(int[][] lights) {
    int ans = Integer.MAX_VALUE;
    int maxBrightness = -1;
    int currBrightness = 0;
    Map<Integer, Integer> line = new TreeMap<>();

    for (int[] light : lights) {
      final int position = light[0];
      final int range = light[1];
      line.merge(position - range, 1, Integer::sum);
      line.merge(position + range + 1, -1, Integer::sum);
    }

    for (final int pos : line.keySet()) {
      final int brightness = line.get(pos);
      currBrightness += brightness;
      if (currBrightness > maxBrightness) {
        maxBrightness = currBrightness;
        ans = pos;
      }
    }

    return ans;
  }
}
