class Solution {
  public String complexNumberMultiply(String num1, String num2) {
    int[] a = getRealAndImag(num1);
    int[] b = getRealAndImag(num2);
    return String.valueOf(a[0] * b[0] - a[1] * b[1]) + "+" +
        String.valueOf(a[0] * b[1] + a[1] * b[0]) + "i";
  }

  private int[] getRealAndImag(final String s) {
    final String real = s.substring(0, s.indexOf('+'));
    final String imag = s.substring(s.indexOf('+') + 1, s.length() - 1);
    return new int[] {Integer.valueOf(real), Integer.valueOf(imag)};
  }
}
