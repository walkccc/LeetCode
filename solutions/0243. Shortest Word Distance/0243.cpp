class Solution {
 public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int ans = words.size();
    int index1 = -1;  // words[index1] == word1
    int index2 = -1;  // words[index2] == word2

    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        index1 = i;
        if (index2 != -1)
          ans = min(ans, index1 - index2);
      }
      if (words[i] == word2) {
        index2 = i;
        if (index1 != -1)
          ans = min(ans, index2 - index1);
      }
    }

    return ans;
  }
};
