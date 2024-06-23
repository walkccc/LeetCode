class Solution {
  public List<Integer> targetIndices(int[] nums, int target) {
    List<Integer> ans = new ArrayList<>();
    final int count = (int) Arrays.stream(nums).filter(num -> num == target).count();
    int lessThan = (int) Arrays.stream(nums).filter(num -> num < target).count();

    for (int i = 0; i < count; ++i)
      ans.add(lessThan++);

    return ans;
  }
}
