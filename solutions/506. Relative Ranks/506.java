class Solution {
  public String[] findRelativeRanks(int[] nums) {
    final int n = nums.length;
    String[] ans = new String[n];
    List<Integer> indices = new ArrayList<>();

    for (int i = 0; i < n; ++i)
      indices.add(i);

    Collections.sort(indices, (a, b) -> nums[b] - nums[a]);

    for (int i = 0; i < n; ++i)
      if (i == 0)
        ans[indices.get(0)] = "Gold Medal";
      else if (i == 1)
        ans[indices.get(1)] = "Silver Medal";
      else if (i == 2)
        ans[indices.get(2)] = "Bronze Medal";
      else
        ans[indices.get(i)] = String.valueOf(i + 1);

    return ans;
  }
}
