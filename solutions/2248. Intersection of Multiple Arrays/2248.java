class Solution {
  public List<Integer> intersection(int[][] nums) {
    List<Integer> ans = new ArrayList<>();
    int[] count = new int[1001];

    for (int[] A : nums)
      for (final int a : A)
        ++count[a];

    for (int i = 1; i < 1001; ++i)
      if (count[i] == nums.length)
        ans.add(i);

    return ans;
  }
}
