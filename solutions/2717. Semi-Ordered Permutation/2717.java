class Solution {
  public int semiOrderedPermutation(int[] nums) {
    final int n = nums.length;
    int index1 = -1;
    int indexN = -1;
    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] == 1)
        index1 = i;
      else if (nums[i] == n)
        indexN = i;
    }
    return index1 + (n - 1 - indexN) - (index1 > indexN ? 1 : 0);
  }
}
