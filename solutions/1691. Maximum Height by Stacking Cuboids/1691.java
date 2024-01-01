class Solution {
  public int maxHeight(int[][] cuboids) {
    // For each cuboid, sort it so that c[0] <= c[1] <= c[2].
    for (int[] cuboid : cuboids)
      Arrays.sort(cuboid);

    Arrays.sort(cuboids, new Comparator<int[]>() {
      @Override
      public int compare(int[] a, int[] b) {
        if (a[0] != b[0])
          return a[0] - b[0];
        if (a[1] != b[1])
          return a[1] - b[1];
        return a[2] - b[2];
      }
    });

    // dp[i] := the maximum height with cuboids[i] in the bottom
    int[] dp = new int[cuboids.length];

    for (int i = 0; i < cuboids.length; ++i)
      dp[i] = cuboids[i][2];

    for (int i = 1; i < cuboids.length; ++i)
      for (int j = 0; j < i; ++j)
        if (cuboids[j][0] <= cuboids[i][0] && //
            cuboids[j][1] <= cuboids[i][1] && //
            cuboids[j][2] <= cuboids[i][2])
          dp[i] = Math.max(dp[i], dp[j] + cuboids[i][2]);

    return Arrays.stream(dp).max().getAsInt();
  }
}
