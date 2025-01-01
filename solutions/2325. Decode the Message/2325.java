class Solution {
  public String decodeMessage(String key, String message) {
    StringBuilder sb = new StringBuilder();
    char[] keyToActual = new char[128];
    keyToActual[' '] = ' ';
    char currChar = 'a';

    for (final char c : key.toCharArray())
      if (keyToActual[c] == 0)
        keyToActual[c] = currChar++;

    for (final char c : message.toCharArray())
      sb.append(keyToActual[c]);

    return sb.toString();
  }
}
