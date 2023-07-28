class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    long maxSpaceCount = 0;

    for (const string& s : sentences)
      maxSpaceCount = max(maxSpaceCount, count(s.begin(), s.end(), ' '));

    return maxSpaceCount + 1;
  }
};
