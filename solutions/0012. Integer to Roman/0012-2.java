class Solution {
  public String intToRoman(int num) {
    final String[] M = {"", "M", "MM", "MMM"};
    final String[] C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    final String[] X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    final String[] I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
  }
}
