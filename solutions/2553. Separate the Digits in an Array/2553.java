class Solution {
  public int[] separateDigits(int[] nums) {
    List<Integer> ans = new ArrayList<>();

    for (final int num : nums)
      for (final char c : String.valueOf(num).toCharArray())
        ans.add(c - '0');

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
