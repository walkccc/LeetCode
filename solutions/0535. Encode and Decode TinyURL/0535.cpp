class Solution {
 public:
  string encode(string longUrl) {
    while (!urlToCode.count(longUrl)) {
      string code;
      for (int i = 0; i < 6; ++i)
        code += alphabets[rand() % alphabets.size()];
      if (!codeToUrl.count(code)) {
        codeToUrl[code] = longUrl;
        urlToCode[longUrl] = code;
        return "http://tinyurl.com/" + code;
      }
    }

    throw;
  }

  string decode(string shortUrl) {
    return codeToUrl[shortUrl.substr(19)];
  }

 private:
  const string alphabets =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  unordered_map<string, string> urlToCode;
  unordered_map<string, string> codeToUrl;
};
