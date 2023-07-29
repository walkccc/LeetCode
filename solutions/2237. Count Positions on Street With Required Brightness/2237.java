class Solution {
  public int meetRequirement(int n, int[][] lights, int[] requirement) {
    int ans = 0;
    int currBrightness = 0;
    int[] change = new int[n + 1];

    for (int[] light : lights) {
      final int position = light[0];
      final int range = light[1];
      ++change[Math.max(0, position - range)];
      --change[Math.min(n, position + range + 1)];
    }

    for (int i = 0; i < n; ++i) {
      currBrightness += change[i];
      if (currBrightness >= requirement[i])
        ++ans;
    }

    return ans;
  }
}
