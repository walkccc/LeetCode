class MagicDictionary {
 public:
  void buildDict(vector<string> dictionary) {
    for (const string& word : dictionary)
      for (int i = 0; i < word.length(); ++i) {
        const string replaced = getReplaced(word, i);
        dict[replaced] = dict.count(replaced) ? '*' : word[i];
      }
  }

  bool search(string searchWord) {
    for (int i = 0; i < searchWord.length(); ++i) {
      const string replaced = getReplaced(searchWord, i);
      if (const auto it = dict.find(replaced);
          it != dict.cend() && it->second != searchWord[i])
        return true;
    }
    return false;
  }

 private:
  unordered_map<string, char> dict;

  string getReplaced(const string& s, int i) {
    return s.substr(0, i) + '*' + s.substr(i + 1);
  }
};
