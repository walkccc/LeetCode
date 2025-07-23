class Solution {
  public int minFallingPathSum(int[][] grid) {
    final int n = grid.length;

    for (int i = 1; i < n; ++i) {
      Pair<Integer, Integer>[] twoMinNumAndIndexes = getTwoMinNumAndIndexes(grid[i - 1]);
      final int firstMinNum = twoMinNumAndIndexes[0].getKey();
      final int firstMinIndex = twoMinNumAndIndexes[0].getValue();
      final int secondMinNum = twoMinNumAndIndexes[1].getKey();
      for (int j = 0; j < n; ++j)
        if (j == firstMinIndex)
          grid[i][j] += secondMinNum;
        else
          grid[i][j] += firstMinNum;
    }

    return Arrays.stream(grid[n - 1]).min().getAsInt();
  }

  private Pair<Integer, Integer>[] getTwoMinNumAndIndexes(int[] arr) {
    List<Pair<Integer, Integer>> numAndIndexes = new ArrayList<>();
    for (int i = 0; i < arr.length; ++i)
      numAndIndexes.add(new Pair<>(arr[i], i));
    Collections.sort(numAndIndexes, Comparator.comparingInt(Pair::getKey));
    return new Pair[] {numAndIndexes.get(0), numAndIndexes.get(1)};
  }
}
