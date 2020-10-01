class ValidWordAbbr {
 public:
  ValidWordAbbr(vector<string>& dictionary) {
    for (const string& word : dictionary)
      if (word.length() > 2) {
        const string abbrev = getAbbrev(word);
        if (abbrevToWord.count(abbrev)) {
          if (abbrevToWord[abbrev] != word)
            abbrevToWord[abbrev] = "";  // mark as "" (is not unique)
        } else {
          abbrevToWord[abbrev] = word;
        }
      }
  }

  bool isUnique(string word) {
    if (word.length() <= 2) return true;

    const string abbrev = getAbbrev(word);
    return !abbrevToWord.count(abbrev) || abbrevToWord[abbrev] == word;
  }

 private:
  unordered_map<string, string> abbrevToWord;

  string getAbbrev(const string& word) {
    const int innerLength = word.length() - 2;
    return word[0] + to_string(innerLength) + word.back();
  }
};