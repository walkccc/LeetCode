class Solution {
  public String largestPalindrome(int n, int k) {
    StringBuilder sb = new StringBuilder();

    switch (k) {
      case 1:
        return "9".repeat(n);
      case 2:
        return n <= 2 ? "8".repeat(n)
                      : sb.append("8") //
                            .append("9".repeat(n - 2))
                            .append("8")
                            .toString();
      case 3:
      case 9:
        return "9".repeat(n);
      case 4:
        return n <= 4 ? "8".repeat(n)
                      : sb.append("88") //
                            .append("9".repeat(n - 4))
                            .append("88")
                            .toString();
      case 5:
        return n <= 2 ? "5".repeat(n)
                      : sb.append("5") //
                            .append("9".repeat(n - 2))
                            .append("5")
                            .toString();
      case 6:
        if (n <= 2) {
          return "6".repeat(n);
        } else if (n % 2 == 1) {
          final int l = n / 2 - 1;
          return sb.append("8")
              .append("9".repeat(l))
              .append("8")
              .append("9".repeat(l))
              .append("8")
              .toString();
        } else {
          final int l = n / 2 - 2;
          return sb.append("8")
              .append("9".repeat(l))
              .append("77")
              .append("9".repeat(l))
              .append("8")
              .toString();
        }
      case 8:
        return n <= 6 ? "8".repeat(n)
                      : sb.append("888") //
                            .append("9".repeat(n - 6))
                            .append("888")
                            .toString();
      default:
        String[] middle = {"",         "7",         "77",         "959",
                           "9779",     "99799",     "999999",     "9994999",
                           "99944999", "999969999", "9999449999", "99999499999"};
        final int q = n / 12;
        final int r = n % 12;
        return sb.append("999999".repeat(q))
            .append(middle[r])
            .append("999999".repeat(q))
            .toString();
    }
  }
}
