class Solution {
  public String validIPAddress(String IP) {
    if (IP.chars().filter(c -> c == '.').count() == 3) {
      for (final String digit : IP.split("\\.", -1))
        if (!isIPv4(digit))
          return "Neither";
      return "IPv4";
    }

    if (IP.chars().filter(c -> c == ':').count() == 7) {
      for (final String digit : IP.split("\\:", -1))
        if (!isIPv6(digit))
          return "Neither";
      return "IPv6";
    }

    return "Neither";
  }

  private static final String validIPv6Chars = "0123456789abcdefABCDEF";

  private boolean isIPv4(final String digit) {
    if (digit.isEmpty() || digit.length() > 3)
      return false;
    if (digit.length() > 1 && digit.charAt(0) == '0')
      return false;

    for (final char c : digit.toCharArray())
      if (c < '0' || c > '9')
        return false;

    final int num = Integer.parseInt(digit);
    return 0 <= num && num <= 255;
  }

  private boolean isIPv6(final String digit) {
    if (digit.isEmpty() || digit.length() > 4)
      return false;

    for (final char c : digit.toCharArray())
      if (!validIPv6Chars.contains("" + c))
        return false;

    return true;
  }
}
