class Solution {
  public String betterCompression(String compressed) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[26];

    for (int i = 0; i < compressed.length();) {
      final char c = compressed.charAt(i++);
      int freq = 0;
      while (i < compressed.length() && Character.isDigit(compressed.charAt(i)))
        freq = freq * 10 + (compressed.charAt(i++) - '0');
      count[c - 'a'] += freq;
    }

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c - 'a'] > 0)
        sb.append(c).append(count[c - 'a']);

    return sb.toString();
  }
}
