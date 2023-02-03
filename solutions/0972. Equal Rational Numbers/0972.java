class Solution {
  public boolean isRationalEqual(String S, String T) {
    return Math.abs(valueOf(S) - valueOf(T)) < 1e-9;
  }

  private double[] ratios = new double[] {1.0, 1.0 / 9, 1.0 / 99, 1.0 / 999, 1.0 / 9999};

  private double valueOf(final String s) {
    if (!s.contains("("))
      return Double.valueOf(s);

    double integer_nonRepeating = Double.valueOf(s.substring(0, s.indexOf('(')));
    int nonRepeatingLength = s.indexOf('(') - s.indexOf('.') - 1;
    int repeating = Integer.parseInt(s.substring(s.indexOf('(') + 1, s.indexOf(')')));
    int repeatingLength = s.indexOf(')') - s.indexOf('(') - 1;

    return integer_nonRepeating +
        repeating * Math.pow(0.1, nonRepeatingLength) * ratios[repeatingLength];
  }
}
