class Solution {
  public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
    List<Integer> ans = new ArrayList<>();
    int[] count = new int[101];

    for (int[] nums : new int[][] {nums1, nums2, nums3})
      update(count, nums);

    for (int i = 1; i <= 100; ++i)
      if (count[i] >= 2)
        ans.add(i);

    return ans;
  }

  private void update(int[] count, int[] nums) {
    for (final int num : Arrays.stream(nums).boxed().collect(Collectors.toSet()))
      ++count[num];
  }
}
