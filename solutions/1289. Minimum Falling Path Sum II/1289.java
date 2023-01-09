class Solution {
  public int minFallingPathSum(int[][] grid) {
    final int n = grid.length;

    for (int i = 1; i < n; ++i) {
      Pair<Integer, Integer>[] twoMinNumAndIndexs = getTwoMinNumAndIndexs(grid[i - 1]);
      final int firstMinNum = twoMinNumAndIndexs[0].getKey();
      final int firstMinIndex = twoMinNumAndIndexs[0].getValue();
      final int secondMinNum = twoMinNumAndIndexs[1].getKey();
      for (int j = 0; j < n; ++j)
        if (j == firstMinIndex)
          grid[i][j] += secondMinNum;
        else
          grid[i][j] += firstMinNum;
    }

    return Arrays.stream(grid[n - 1]).min().getAsInt();
  }

  private Pair<Integer, Integer>[] getTwoMinNumAndIndexs(int[] A) {
    List<Pair<Integer, Integer>> numAndIndexs = new ArrayList<>();

    for (int i = 0; i < A.length; ++i)
      numAndIndexs.add(new Pair<>(A[i], i));

    Collections.sort(numAndIndexs, (a, b) -> a.getKey() - b.getKey());
    return new Pair[] {numAndIndexs.get(0), numAndIndexs.get(1)};
  }
}
