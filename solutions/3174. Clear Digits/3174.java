class Solution {
  public String clearDigits(String s) {
    StringBuilder sb = new StringBuilder();

    for (final char c : s.toCharArray())
      if (Character.isDigit(c))
        // Since `sb` only contains non-digit characters, popping the last
        // character is equivalent to deleting the closest non-digit character.
        sb.setLength(sb.length() - 1);
      else
        sb.append(c);

    return sb.toString();
  }
}
