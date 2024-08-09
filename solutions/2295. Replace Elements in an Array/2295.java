class Solution {
  public int[] arrayChange(int[] nums, int[][] operations) {
    Map<Integer, Integer> numToIndex = new HashMap<>();

    for (int i = 0; i < nums.length; ++i)
      numToIndex.put(nums[i], i);

    for (int[] o : operations) {
      final int original = o[0];
      final int replaced = o[1];
      final int index = numToIndex.get(original);
      nums[index] = replaced;
      numToIndex.remove(original);
      numToIndex.put(replaced, index);
    }

    return nums;
  }
}
