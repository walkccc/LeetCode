class Solution {
  public String discountPrices(String sentence, int discount) {
    final int kPrecision = 2;
    StringBuilder sb = new StringBuilder();

    for (final String word : sentence.split(" "))
      if (word.charAt(0) == '$' && word.length() > 1) {
        final String digits = word.substring(1);
        if (digits.chars().allMatch(c -> Character.isDigit(c))) {
          final double val = Double.parseDouble(digits) * (100 - discount) / 100;
          final String s = String.format("%.2f", val);
          final String trimmed = s.substring(0, s.indexOf(".") + kPrecision + 1);
          sb.append("$").append(trimmed).append(" ");
        } else {
          sb.append(word).append(" ");
        }
      } else {
        sb.append(word).append(" ");
      }

    sb.deleteCharAt(sb.length() - 1);
    return sb.toString();
  }
}
