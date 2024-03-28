class Solution {
  public int maximumSetSize(int[] nums1, int[] nums2) {
    Set<Integer> set1 = Arrays.stream(nums1).boxed().collect(Collectors.toSet());
    Set<Integer> set2 = Arrays.stream(nums2).boxed().collect(Collectors.toSet());
    Set<Integer> common = new HashSet<>();

    for (final int num1 : set1)
      if (set2.contains(num1))
        common.add(num1);

    final int n = nums1.length;
    final int n1 = set1.size();
    final int n2 = set2.size();
    final int nc = common.size();
    final int maxUniqueNums1 = Math.min(n1 - nc, n / 2);
    final int maxUniqueNums2 = Math.min(n2 - nc, n / 2);
    return Math.min(n, maxUniqueNums1 + maxUniqueNums2 + nc);
  }
}
