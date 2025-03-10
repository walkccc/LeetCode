class Solution {
 public:
  int countValidWords(string sentence) {
    int ans = 0;
    istringstream iss(sentence);

    for (string token; iss >> token;)
      if (isValid(token))
        ++ans;

    return ans;
  }

 private:
  bool isValid(const string& token) {
    int countHyphen = 0;
    for (int i = 0; i < token.length(); ++i) {
      const char c = token[i];
      if (isdigit(c))
        return false;
      if (c == '-') {
        if (i == 0 || !isalpha(token[i - 1]))
          return false;
        if (i + 1 == token.length() || !isalpha(token[i + 1]))
          return false;
        if (++countHyphen > 1)
          return false;
      } else if (c == '!' || c == '.' || c == ',') {
        if (i != token.length() - 1)
          return false;
      }
    }
    return true;
  }
};
