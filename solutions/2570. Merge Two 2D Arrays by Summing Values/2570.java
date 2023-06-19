class Solution {
  public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
    final int kMax = 1000;
    List<int[]> ans = new ArrayList<>();
    int[] count = new int[kMax + 1];

    addCount(nums1, count);
    addCount(nums2, count);

    for (int i = 1; i <= kMax; ++i)
      if (count[i] > 0)
        ans.add(new int[] {i, count[i]});

    return ans.stream().toArray(int[][] ::new);
  }

  private void addCount(int[][] nums, int[] count) {
    for (int[] idAndVal : nums) {
      final int id = idAndVal[0];
      final int val = idAndVal[1];
      count[id] += val;
    }
  }
}
