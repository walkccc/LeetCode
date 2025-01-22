class Solution {
 public:
  bool arrayStringsAreEqual(std::vector<std::string>& word1,
                            std::vector<std::string>& word2) {
    int i = 0;  // word1's index
    int j = 0;  // word2's index
    int a = 0;  // word1[i]'s index
    int b = 0;  // word2[j]'s index

    while (i < word1.size() && j < word2.size()) {
      if (word1[i][a] != word2[j][b])
        return false;
      if (++a == word1[i].size()) {
        ++i;
        a = 0;
      }
      if (++b == word2[j].size()) {
        ++j;
        b = 0;
      }
    }

    return i == word1.size() && j == word2.size();
  }
};
