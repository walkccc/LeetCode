class Solution {
  public int[] intersection(int[] nums1, int[] nums2) {
    List<Integer> ans = new ArrayList<>();
    Set<Integer> set = Arrays.stream(nums1).boxed().collect(Collectors.toSet());

    for (final int num : nums2)
      if (set.remove(num))
        ans.add(num);

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
