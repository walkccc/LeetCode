class Solution {
 public:
  string entityParser(string text) {
    const unordered_map<string, char> entityToChar{
        {"&quot;", '"'}, {"&apos;", '\''}, {"&amp;", '&'},
        {"&gt;", '>'},   {"&lt;", '<'},    {"&frasl;", '/'}};
    string ans;
    int j = 0;  // text[j..ampersandIndex - 1] is the pending substring.
    int ampersandIndex = -1;

    for (int i = 0; i < text.length(); ++i)
      if (text[i] == '&') {
        ampersandIndex = i;
      } else if (text[i] == ';' && ampersandIndex >= j) {
        const string sub = text.substr(ampersandIndex, i - ampersandIndex + 1);
        ans += text.substr(j, ampersandIndex - j);
        ans += getCharIfMatched(text, sub, entityToChar);
        j = i + 1;
      }

    return ans + text.substr(j);
  }

 private:
  string getCharIfMatched(const string& text, const string& sub,
                          const unordered_map<string, char>& entityToChar) {
    for (const auto& [entity, c] : entityToChar)
      if (entity == sub)
        return string(1, c);
    return sub;
  }
};
