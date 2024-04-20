class Solution {
  public int numDifferentIntegers(String word) {
    HashSet<String> nums = new HashSet<>();
    StringBuilder sb = new StringBuilder();

    for (final char c : word.toCharArray())
      if (Character.isDigit(c)) {
        sb.append(c);
      } else if (sb.length() > 0) {
        nums.add(removeLeadingZeros(sb.toString()));
        sb = new StringBuilder();
      }

    if (sb.length() > 0)
      nums.add(removeLeadingZeros(sb.toString()));
    return nums.size();
  }

  private String removeLeadingZeros(final String s) {
    int index = 0;
    while (index < s.length() && s.charAt(index) == '0')
      ++index;
    return index == s.length() ? "0" : s.substring(index);
  }
}
