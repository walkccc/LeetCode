class Solution {
 public:
  bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    const unordered_set<string> bannedWordsSet{bannedWords.begin(),
                                               bannedWords.end()};
    int count = 0;

    for (const string& word : message)
      if (bannedWordsSet.contains(word) && ++count > 1)
        return true;

    return false;
  }
};
