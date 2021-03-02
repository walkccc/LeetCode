class Solution {
  public int[] intersect(int[] nums1, int[] nums2) {
    if (nums1.length > nums2.length)
      return intersect(nums2, nums1);

    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums1)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (final int num : nums2)
      if (count.containsKey(num) && count.get(num) > 0) {
        ans.add(num);
        count.put(num, count.get(num) - 1);
      }

    return ans.stream().mapToInt(i -> i).toArray();
  }
}
