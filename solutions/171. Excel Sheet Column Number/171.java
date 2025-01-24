class Solution {
  public int titleToNumber(String columnTitle) {
    return columnTitle.chars().reduce(0, (subtotal, c) -> subtotal * 26 + c - '@');
  }
}
