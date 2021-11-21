class Solution {
  public boolean makesquare(int[] nums) {
    if (nums.length < 4)
      return false;

    final int perimeter = Arrays.stream(nums).sum();
    if (perimeter % 4 != 0)
      return false;

    int[] edges = new int[4];

    Arrays.fill(edges, perimeter / 4);
    Arrays.sort(edges); // can't do "Arrays.sort(edges, (a, b) -> b - a);" in Java

    return dfs(nums, nums.length - 1, edges);
  }

  private boolean dfs(int[] nums, int selected, int[] edges) {
    if (selected == -1)
      return Arrays.stream(edges).allMatch(edge -> edge == 0);

    for (int i = 0; i < 4; ++i) {
      if (nums[selected] > edges[i])
        continue;
      edges[i] -= nums[selected];
      if (dfs(nums, selected - 1, edges))
        return true;
      edges[i] += nums[selected];
    }

    return false;
  }
}
