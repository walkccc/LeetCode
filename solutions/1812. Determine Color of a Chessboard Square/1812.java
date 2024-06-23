class Solution {
  public boolean squareIsWhite(String coordinates) {
    final char letter = coordinates.charAt(0);
    final char digit = coordinates.charAt(1);
    return letter % 2 != digit % 2;
  }
}
