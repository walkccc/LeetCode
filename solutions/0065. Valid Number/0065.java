class Solution {
  public boolean isNumber(String s) {
    s = s.trim();
    if (s.isEmpty())
      return false;

    boolean seenNum = false;
    boolean seenDot = false;
    boolean seenE = false;

    for (int i = 0; i < s.length(); ++i) {
      switch (s.charAt(i)) {
        case '.':
          if (seenDot || seenE)
            return false;
          seenDot = true;
          break;
        case 'e':
        case 'E':
          if (seenE || !seenNum)
            return false;
          seenE = true;
          seenNum = false;
          break;
        case '+':
        case '-':
          if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E')
            return false;
          seenNum = false;
          break;
        default:
          if (!Character.isDigit(s.charAt(i)))
            return false;
          seenNum = true;
      }
    }

    return seenNum;
  }
}
