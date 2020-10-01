class Solution {
  public boolean makesquare(int[] nums) {
    if (nums.length < 4)
      return false;

    int perimeter = Arrays.stream(nums).sum();
    if (perimeter % 4 != 0)
      return false;

    int[] edges = new int[4];
    Arrays.fill(edges, perimeter / 4);
    Arrays.sort(edges);

    return dfs(nums, nums.length - 1, edges);
  }

  private boolean dfs(int[] nums, int selected, int[] edges) {
    if (selected == -1)
      return edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3];

    for (int i = 0; i < edges.length; ++i) {
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