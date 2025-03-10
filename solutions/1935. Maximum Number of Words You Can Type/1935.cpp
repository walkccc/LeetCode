class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    int ans = 0;
    istringstream iss(text);
    vector<bool> broken(26);

    for (const char c : brokenLetters)
      broken[c - 'a'] = true;

    for (string word; iss >> word;)
      ans += canBeTyped(word, broken);

    return ans;
  }

 private:
  bool canBeTyped(const string& word, const vector<bool>& broken) {
    for (const char c : word)
      if (broken[c - 'a'])
        return false;
    return true;
  }
};
