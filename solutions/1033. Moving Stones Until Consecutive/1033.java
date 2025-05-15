class Solution {
  public int[] numMovesStones(int a, int b, int c) {
    int[] nums = new int[] {a, b, c};

    Arrays.sort(nums);

    if (nums[2] - nums[0] == 2)
      return new int[] {0, 0};
    return new int[] {Math.min(nums[1] - nums[0], nums[2] - nums[1]) <= 2 ? 1 : 2,
                      nums[2] - nums[0] - 2};
  }
}
