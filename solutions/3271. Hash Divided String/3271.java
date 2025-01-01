class Solution {
  public String stringHash(String s, int k) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < s.length(); i += k) {
      int sumHash = 0;
      for (int j = i; j < i + k; ++j)
        sumHash += s.charAt(j) - 'a';
      sb.append((char) ('a' + sumHash % 26));
    }

    return sb.toString();
  }
}
