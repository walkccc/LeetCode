/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *  public:
 *   int guess(string word);
 * };
 */
class Solution {
 public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    srand(time(nullptr));

    for (int i = 0; i < 10; ++i) {
      const string& guessedWord = wordlist[rand() % wordlist.size()];
      const int matches = master.guess(guessedWord);
      if (matches == 6)
        break;
      vector<string> updated;
      for (const string& word : wordlist)
        if (getMatches(guessedWord, word) == matches)
          updated.push_back(word);
      wordlist = std::move(updated);
    }
  }

 private:
  int getMatches(const string& s1, const string& s2) {
    int matches = 0;
    for (int i = 0; i < s1.length(); ++i)
      if (s1[i] == s2[i])
        ++matches;
    return matches;
  }
};
