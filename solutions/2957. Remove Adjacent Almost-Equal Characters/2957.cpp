class Solution {
 public:
  int removeAlmostEqualCharacters(string word) {
    int ans = 0;

    int i = 1;
    while (i < word.length())
      if (abs(word[i] - word[i - 1]) <= 1) {
        ++ans;
        i += 2;
      } else {
        i += 1;
      }

    return ans;
  }
};
