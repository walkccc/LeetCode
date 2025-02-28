class Solution {
  public int minAbsDifference(int[] nums, int goal) {
    final int n = nums.length / 2;
    final int[] lNums = Arrays.copyOfRange(nums, 0, n);
    final int[] rNums = Arrays.copyOfRange(nums, n, nums.length);
    int ans = Integer.MAX_VALUE;
    List<Integer> lSums = new ArrayList<>();
    List<Integer> rSums = new ArrayList<>();

    dfs(lNums, 0, 0, lSums);
    dfs(rNums, 0, 0, rSums);
    Collections.sort(rSums);

    for (final int lSum : lSums) {
      final int i = firstGreaterEqual(rSums, goal - lSum);
      if (i < rSums.size()) // 2^n
        ans = Math.min(ans, Math.abs(goal - lSum - rSums.get(i)));
      if (i > 0)
        ans = Math.min(ans, Math.abs(goal - lSum - rSums.get(i - 1)));
    }

    return ans;
  }

  private void dfs(int[] arr, int i, int path, List<Integer> sums) {
    if (i == arr.length) {
      sums.add(path);
      return;
    }
    dfs(arr, i + 1, path + arr[i], sums);
    dfs(arr, i + 1, path, sums);
  }

  private int firstGreaterEqual(List<Integer> arr, int target) {
    final int i = Collections.binarySearch(arr, target);
    return i < 0 ? -i - 1 : i;
  }
}
