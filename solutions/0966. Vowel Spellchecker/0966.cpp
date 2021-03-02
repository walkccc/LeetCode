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
      if (dict.count(query))
        ans.push_back(dict[query]);
      else if (dict.count(lowerKey(query)))
        ans.push_back(dict[lowerKey(query)]);
      else if (dict.count(vowelKey(query)))
        ans.push_back(dict[vowelKey(query)]);
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
