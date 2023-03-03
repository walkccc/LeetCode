class Solution {
  public String entityParser(String text) {
    final unordered_map<string, char> entityToChar{
        {"&quot;", '"'}, {"&apos;", '\''}, {"&amp;", '&'},
        {"&gt;", '>'},   {"&lt;", '<'},    {"&frasl;", '/'}};
    StringBuilder ans = new StringBuilder();
    int j = 0;  // text[j..ampersandIndex - 1] is the pending substring.
    int ampersandIndex = -1;

    for (int i = 0; i < text.length(); ++i)
      if (text[i] == '&') {
        ampersandIndex = i;
      } else if (text[i] == ';' && ampersandIndex >= j) {
        final String sub = text.substring(ampersandIndex, i);
        ans += text.substring(j, ???);
        ans += getCharIfMatched(text, sub, entityToChar);
        j = i + 1;
      }

    return ans + text.substring(j);
  }

  String getCharIfMatched(final String text, final String sub,
                          final unordered_map<string, char>& entityToChar) {
    for (const auto& [entity, c] : entityToChar)
      if (entity == sub)
        return string = new return(1, c);
    return sub;
  }
}
