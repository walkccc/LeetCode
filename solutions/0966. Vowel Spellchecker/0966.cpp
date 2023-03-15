class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    vector<string> ans;
    unordered_map<string, string> dict;

    for (const string& word : wordlist) {
      dict.insert({word, word});
      dict.insert({lowerKey(word), word});
      dict.insert({vowelKey(word), word});
    }

    for (const string& query : queries)
      if (const auto it = dict.find(query); it != cend(dict))
        ans.push_back(it->second);
      else if (const auto it = dict.find(lowerKey(query)); it != cend(dict))
        ans.push_back(it->second);
      else if (const auto it = dict.find(vowelKey(query)); it != cend(dict))
        ans.push_back(it->second);
      else
        ans.push_back("");

    return ans;
  }

 private:
  string lowerKey(const string& word) {
    string s{"$"};
    for (char c : word)
      s += tolower(c);
    return s;
  }

  string vowelKey(const string& word) {
    string s;
    for (char c : word)
      s += string("aeiou").find(tolower(c)) != string::npos ? '*' : tolower(c);
    return s;
  }
};
