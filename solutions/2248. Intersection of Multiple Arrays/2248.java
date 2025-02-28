class Solution {
  public List<Integer> intersection(int[][] nums) {
    final int kMax = 1000;
    List<Integer> ans = new ArrayList<>();
    int[] count = new int[kMax + 1];

    for (int[] arr : nums)
      for (final int a : arr)
        ++count[a];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] == nums.length)
        ans.add(i);

    return ans;
  }
}
