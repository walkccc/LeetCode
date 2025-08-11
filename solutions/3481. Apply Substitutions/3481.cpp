class Solution {
 public:
  string applySubstitutions(vector<vector<string>>& replacements, string text) {
    unordered_map<string, string> replaceMap;

    for (const vector<string>& replacement : replacements) {
      const string& key = replacement[0];
      const string& value = replacement[1];
      replaceMap[key] = value;
    }

    return evaluate(text, replaceMap);
  }

 private:
  // Evaluates the `text` and replaces the placeholders with the values
  // from the `replaceMap` recursively.
  string evaluate(const string& text,
                  const unordered_map<string, string>& replaceMap) {
    string res;
    int i = 0;
    while (i < text.length())
      if (text[i] == '%') {
        const int j = i + 1 + text.substr(i + 1).find('%');
        const string key = text.substr(i + 1, j - i - 1);
        const string value = replaceMap.at(key);
        res += evaluate(value, replaceMap);
        i = j + 1;
      } else {
        res += text[i++];
      }
    return res;
  }
};
