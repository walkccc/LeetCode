class ValidWordAbbr {
 public:
  ValidWordAbbr(vector<string>& dictionary) {
    dict = unordered_set(dictionary.begin(), dictionary.end());

    for (const string& word : dict) {
      const string& abbr = getAbbr(word);
      abbrUnique[abbr] = !abbrUnique.count(abbr);
    }
  }

  bool isUnique(string word) {
    const string& abbr = getAbbr(word);
    return !abbrUnique.count(abbr) || abbrUnique[abbr] && dict.count(word);
  }

 private:
  unordered_set<string> dict;
  unordered_map<string, bool> abbrUnique;  // T := unique, F := not unique

  string getAbbr(const string& s) {
    const int n = s.length();
    if (n <= 2)
      return s;
    return s[0] + to_string(n - 2) + s.back();
  }
};
