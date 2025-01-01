class Solution {
  public int numSquarefulPerms(int[] nums) {
    boolean[] used = new boolean[nums.length];
    Arrays.sort(nums);
    dfs(nums, used, new ArrayList<>());
    return ans;
  }

  private int ans = 0;

  private void dfs(int[] nums, boolean[] used, List<Integer> path) {
    if (path.size() > 1 && !isSquare(path.get(path.size() - 1) + path.get(path.size() - 2)))
      return;
    if (path.size() == nums.length) {
      ++ans;
      return;
    }

    for (int i = 0; i < nums.length; ++i) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.add(nums[i]);
      dfs(nums, used, path);
      path.remove(path.size() - 1);
      used[i] = false;
    }
  }

  private boolean isSquare(int num) {
    int root = (int) Math.sqrt(num);
    return root * root == num;
  }
}
