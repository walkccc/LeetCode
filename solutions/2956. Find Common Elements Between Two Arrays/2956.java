class Solution {
  public int[] findIntersectionValues(int[] nums1, int[] nums2) {
    Set<Integer> nums1Set = Arrays.stream(nums1).boxed().collect(Collectors.toSet());
    Set<Integer> nums2Set = Arrays.stream(nums2).boxed().collect(Collectors.toSet());
    final int ans1 = (int) Arrays.stream(nums1).filter(nums2Set::contains).count();
    final int ans2 = (int) Arrays.stream(nums2).filter(nums1Set::contains).count();
    return new int[] {ans1, ans2};
  }
}
