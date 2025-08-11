class Solution {
  public int minimumDifference(int[] nums) {
    final int n = nums.length / 2;
    final int sum = Arrays.stream(nums).sum();
    final int goal = sum / 2;
    final int[] lNums = Arrays.copyOfRange(nums, 0, n);
    final int[] rNums = Arrays.copyOfRange(nums, n, nums.length);
    int ans = Integer.MAX_VALUE;
    List<Integer>[] lSums = new List[n + 1];
    List<Integer>[] rSums = new List[n + 1];

    for (int i = 0; i <= n; ++i) {
      lSums[i] = new ArrayList<>();
      rSums[i] = new ArrayList<>();
    }

    dfs(lNums, 0, 0, 0, lSums);
    dfs(rNums, 0, 0, 0, rSums);

    for (int lCount = 0; lCount <= n; ++lCount) {
      List<Integer> l = lSums[lCount];
      List<Integer> r = rSums[n - lCount];
      Collections.sort(r);
      for (final int lSum : l) {
        final int i = firstGreaterEqual(r, goal - lSum);
        if (i < r.size()) {
          final int sumPartOne = sum - lSum - r.get(i);
          final int sumPartTwo = sum - sumPartOne;
          ans = Math.min(ans, Math.abs(sumPartOne - sumPartTwo));
        }
        if (i > 0) {
          final int sumPartOne = sum - lSum - r.get(i - 1);
          final int sumPartTwo = sum - sumPartOne;
          ans = Math.min(ans, Math.abs(sumPartOne - sumPartTwo));
        }
      }
    }

    return ans;
  }

  private void dfs(int[] arr, int i, int count, int path, List<Integer>[] sums) {
    if (i == arr.length) {
      sums[count].add(path);
      return;
    }
    dfs(arr, i + 1, count + 1, path + arr[i], sums);
    dfs(arr, i + 1, count, path, sums);
  }

  private int firstGreaterEqual(List<Integer> arr, int target) {
    final int i = Collections.binarySearch(arr, target);
    return i < 0 ? -i - 1 : i;
  }
}
