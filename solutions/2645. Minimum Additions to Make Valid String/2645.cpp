class Solution {
 public:
  int addMinimum(string word) {
    const string letters = "abc";
    int ans = 0;
    int i = 0;

    while (i < word.length())
      for (const char c : letters) {
        if (i < word.length() && word[i] == c)
          ++i;
        else
          ++ans;
      }

    return ans;
  }
};
