class Solution {
 public:
  string largestMerge(string word1, string word2) {
    if (word1.empty())
      return word2;
    if (word2.empty())
      return word1;
    return word1 > word2 ? word1[0] + largestMerge(word1.substr(1), word2)
                         : word2[0] + largestMerge(word1, word2.substr(1));
  }
};
