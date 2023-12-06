class Solution {
  public boolean checkZeroOnes(String s) {
    int longestOnes = 0;
    int longestZeros = 0;
    int currentOnes = 0;
    int currentZeros = 0;

    for (final char c : s.toCharArray())
      if (c == '0') {
        currentOnes = 0;
        longestZeros = Math.max(longestZeros, ++currentZeros);
      } else {
        currentZeros = 0;
        longestOnes = Math.max(longestOnes, ++currentOnes);
      }

    return longestOnes > longestZeros;
  }
}
