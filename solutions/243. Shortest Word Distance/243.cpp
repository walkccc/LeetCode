class Solution {
 public:
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int ans = wordsDict.size();
    int index1 = -1;  // wordsDict[index1] == word1
    int index2 = -1;  // wordsDict[index2] == word2

    for (int i = 0; i < wordsDict.size(); ++i) {
      if (wordsDict[i] == word1) {
        index1 = i;
        if (index2 != -1)
          ans = min(ans, index1 - index2);
      }
      if (wordsDict[i] == word2) {
        index2 = i;
        if (index1 != -1)
          ans = min(ans, index2 - index1);
      }
    }

    return ans;
  }
};
