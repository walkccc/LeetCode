class Solution {
  public boolean isRationalEqual(String s, String t) {
    return Math.abs(valueOf(s) - valueOf(t)) < 1e-9;
  }

  private static double[] ratios = new double[] {1.0, 1.0 / 9, 1.0 / 99, 1.0 / 999, 1.0 / 9999};

  private double valueOf(final String s) {
    if (!s.contains("("))
      return Double.valueOf(s);

    // Get the indices..
    final int leftParenIndex = s.indexOf('(');
    final int rightParenIndex = s.indexOf(')');
    final int dotIndex = s.indexOf('.');

    // integerAndNonRepeating := <IntegerPart><.><NonRepeatingPart>
    final double nonRepeating = Double.valueOf(s.substring(0, leftParenIndex));
    final int nonRepeatingLength = leftParenIndex - dotIndex - 1;

    // repeating := <RepeatingPart>
    final int repeating = Integer.parseInt(s.substring(leftParenIndex + 1, rightParenIndex));
    final int repeatingLength = rightParenIndex - leftParenIndex - 1;
    return nonRepeating + repeating * Math.pow(0.1, nonRepeatingLength) * ratios[repeatingLength];
  }
}
