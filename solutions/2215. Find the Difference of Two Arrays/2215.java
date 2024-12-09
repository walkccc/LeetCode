class Solution {
  public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
    Set<Integer> set1 = Arrays.stream(nums1).boxed().collect(Collectors.toSet());
    Set<Integer> set2 = Arrays.stream(nums2).boxed().collect(Collectors.toSet());
    Arrays.stream(nums1).forEach(set2::remove);
    Arrays.stream(nums2).forEach(set1::remove);
    return Arrays.asList(new ArrayList<>(set1), new ArrayList<>(set2));
  }
}
