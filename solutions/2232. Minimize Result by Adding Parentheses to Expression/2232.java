class Solution {
  public String minimizeResult(String expression) {
    final int plusIndex = expression.indexOf('+');
    final String left = expression.substring(0, plusIndex);
    final String right = expression.substring(plusIndex + 1);
    String ans = "";
    int mn = Integer.MAX_VALUE;

    // the expression -> a * (b + c) * d
    for (int i = 0; i < left.length(); ++i)
      for (int j = 0; j < right.length(); ++j) {
        final int a = i == 0 ? 1 : Integer.parseInt(left.substring(0, i));
        final int b = Integer.parseInt(left.substring(i));
        final int c = Integer.parseInt(right.substring(0, j + 1));
        final int d = j == right.length() - 1 ? 1 : Integer.parseInt(right.substring(j + 1));
        final int val = a * (b + c) * d;
        if (val < mn) {
          mn = val;
          ans = (i == 0 ? "" : String.valueOf(a)) + '(' + String.valueOf(b) + '+' +
                String.valueOf(c) + ')' + (j == right.length() - 1 ? "" : String.valueOf(d));
        }
      }

    return ans;
  }
}
