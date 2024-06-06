class Solution {
  public int minimizeTheDifference(int[][] mat, int target) {
    final int minSum = Arrays.stream(mat).mapToInt(A -> Arrays.stream(A).min().getAsInt()).sum();
    if (minSum >= target) // No need to consider any larger combination.
      return minSum - target;

    final int maxSum = Arrays.stream(mat).mapToInt(A -> Arrays.stream(A).max().getAsInt()).sum();
    Integer[][] mem = new Integer[mat.length][maxSum + 1];
    return minimizeTheDifference(mat, 0, 0, target, mem);
  }

  private int minimizeTheDifference(int[][] mat, int i, int sum, int target, Integer[][] mem) {
    if (i == mat.length)
      return Math.abs(sum - target);
    if (mem[i][sum] != null)
      return mem[i][sum];
    int res = Integer.MAX_VALUE;
    for (final int num : mat[i])
      res = Math.min(res, minimizeTheDifference(mat, i + 1, sum + num, target, mem));
    return mem[i][sum] = res;
  }
}
