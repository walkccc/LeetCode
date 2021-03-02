class Solution {
  public String largestNumber(int[] nums) {
    StringBuilder sb = new StringBuilder();
    String[] strings = new String[nums.length];

    for (int i = 0; i < nums.length; ++i)
      strings[i] = String.valueOf(nums[i]);

    Arrays.sort(strings, (a, b) -> (b + a).compareTo(a + b));

    for (final String s : strings)
      sb.append(s);

    return sb.charAt(0) == '0' ? "0" : sb.toString();
  }
}
