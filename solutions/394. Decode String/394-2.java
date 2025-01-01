class Solution {
  public String decodeString(String s) {
    StringBuilder sb = new StringBuilder();

    while (i < s.length() && s.charAt(i) != ']')
      if (Character.isDigit(s.charAt(i))) {
        int k = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i)))
          k = k * 10 + (s.charAt(i++) - '0');
        ++i; // '['
        final String decodedString = decodeString(s);
        ++i; // ']'
        while (k-- > 0)
          sb.append(decodedString);
      } else {
        sb.append(s.charAt(i++));
      }

    return sb.toString();
  }

  private int i = 0;
}
