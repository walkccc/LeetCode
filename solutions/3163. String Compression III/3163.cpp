class Solution {
 public:
  string compressedString(string word) {
    const int n = word.length();
    string ans;

    for (int i = 0, j = 0; i < n; i = j) {
      int count = 0;
      while (j < n && word[j] == word[i] && count < 9) {
        ++j;
        ++count;
      }
      ans += to_string(count) + word[i];
    }

    return ans;
  }
};
