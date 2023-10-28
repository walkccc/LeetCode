class Solution {
  public String removeTrailingZeros(String num) {
    return num.replaceAll("0+$", "");
  }
}
