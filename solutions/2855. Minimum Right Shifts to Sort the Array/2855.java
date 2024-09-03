class Solution {
  public int minimumRightShifts(List<Integer> nums) {
    int pivot = -1;
    int count = 0;

    for (int i = 0; i + 1 < nums.size(); i++)
      if (nums.get(i) > nums.get(i + 1)) {
        ++count;
        pivot = i;
      }

    if (count == 0)
      return 0;
    if (count > 1 || nums.get(nums.size() - 1) > nums.get(0))
      return -1;
    return nums.size() - 1 - pivot;
  }
}
