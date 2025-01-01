class Solution {
  public String minimizeStringValue(String s) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[26];
    List<Character> letters = new ArrayList<>();

    for (final char c : s.toCharArray())
      if (c != '?')
        ++count[c - 'a'];

    for (final char c : s.toCharArray()) {
      if (c != '?')
        continue;
      final char minFreqLetter = getMinFreqLetter(count);
      letters.add(minFreqLetter);
      ++count[minFreqLetter - 'a'];
    }

    Collections.sort(letters);
    int i = 0; // letters' index

    for (final char c : s.toCharArray())
      sb.append(c == '?' ? letters.get(i++) : c);

    return sb.toString();
  }

  private char getMinFreqLetter(int[] count) {
    char minFreqLetter = 'a';
    for (char c = 'b'; c <= 'z'; ++c)
      if (count[c - 'a'] < count[minFreqLetter - 'a'])
        minFreqLetter = c;
    return minFreqLetter;
  }
}
