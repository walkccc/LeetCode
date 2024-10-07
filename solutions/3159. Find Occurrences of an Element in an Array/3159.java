class Solution {
  public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
    List<Integer> indices = getIndices(nums, x);
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; i++)
      ans[i] = queries[i] <= indices.size() ? indices.get(queries[i] - 1) : -1;

    return ans;
  }

  private List<Integer> getIndices(int[] nums, int x) {
    List<Integer> indices = new ArrayList<>();
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == x)
        indices.add(i);
    return indices;
  }
}
