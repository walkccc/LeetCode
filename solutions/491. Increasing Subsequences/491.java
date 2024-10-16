class Solution {
  public List<List<Integer>> findSubsequences(int[] nums) {
    List<List<Integer>> ans = new LinkedList<>();
    dfs(nums, 0, new LinkedList<>(), ans);
    return ans;
  }

  private void dfs(int[] nums, int s, LinkedList<Integer> path, List<List<Integer>> ans) {
    if (path.size() > 1)
      ans.add(new LinkedList<>(path));

    Set<Integer> used = new HashSet<>();

    for (int i = s; i < nums.length; ++i) {
      if (used.contains(nums[i]))
        continue;
      if (path.isEmpty() || nums[i] >= path.getLast()) {
        used.add(nums[i]);
        path.addLast(nums[i]);
        dfs(nums, i + 1, path, ans);
        path.removeLast();
      }
    }
  }
}
