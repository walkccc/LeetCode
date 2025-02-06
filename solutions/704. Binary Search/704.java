class Solution {
  public int search(int[] nums, int target) {
    final int i = Arrays.binarySearch(nums, target);
    return i < 0 ? -1 : i;
  }
}
