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

    for (const string& q : queries)
      if (dict.count(q))
        ans.push_back(dict[q]);
      else if (dict.count(lowerKey(q)))
        ans.push_back(dict[lowerKey(q)]);
      else if (dict.count(vowelKey(q)))
        ans.push_back(dict[vowelKey(q)]);
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
