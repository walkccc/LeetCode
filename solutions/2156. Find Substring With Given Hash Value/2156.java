class Solution {
  public String subStrHash(String s, int power, int modulo, int k, int hashValue) {
    long maxPower = 1;
    long hash = 0;
    int bestLeft = -1;

    for (int i = s.length() - 1; i >= 0; --i) {
      hash = (hash * power + val(s.charAt(i))) % modulo;
      if (i + k < s.length())
        hash = (hash - val(s.charAt(i + k)) * maxPower % modulo + modulo) % modulo;
      else
        maxPower = maxPower * power % modulo;
      if (hash == hashValue)
        bestLeft = i;
    }

    return s.substring(bestLeft, bestLeft + k);
  }

  private int val(char c) {
    return c - 'a' + 1;
  }
}
