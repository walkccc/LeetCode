class Solution {
  public Solution(int[] nums) {
    this.nums = nums;
  }

  public int pick(int target) {
    int ans = -1;
    int range = 0;

    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == target && rand.nextInt(++range) == 0)
        ans = i;

    return ans;
  }

  private int[] nums;
  private Random rand = new Random();
}
