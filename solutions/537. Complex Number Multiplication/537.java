class Solution {
  public String complexNumberMultiply(String a, String b) {
    int[] A = getRealAndImag(a);
    int[] B = getRealAndImag(b);
    return String.valueOf(A[0] * B[0] - A[1] * B[1]) + "+" +
        String.valueOf(A[0] * B[1] + A[1] * B[0]) + "i";
  }

  private int[] getRealAndImag(final String s) {
    final String real = s.substring(0, s.indexOf('+'));
    final String imag = s.substring(s.indexOf('+') + 1, s.length() - 1);
    return new int[] {Integer.valueOf(real), Integer.valueOf(imag)};
  }
}
