class Solution {
  public int countWays(List<Integer> nums) {
    nums.add(-1);
    nums.add(Integer.MAX_VALUE);
    Collections.sort(nums);

    int ans = 0;

    // i := # of selected nums
    for (int i = 0; i + 1 < nums.size(); ++i)
      if (nums.get(i) < i && i < nums.get(i + 1))
        ++ans;

    return ans;
  }
}
