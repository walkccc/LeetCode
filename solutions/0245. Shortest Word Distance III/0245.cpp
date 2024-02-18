class Solution {
 public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    const bool isSame = word1 == word2;
    int ans = INT_MAX;
    // If word1 == word2, index1 is the newest index.
    int index1 = words.size();
    // If word1 == word2, index2 is the previous index.
    int index2 = -words.size();

    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        if (isSame)
          index2 = index1;
        index1 = i;
      } else if (words[i] == word2) {
        index2 = i;
      }
      ans = min(ans, abs(index1 - index2));
    }

    return ans;
  }
};
