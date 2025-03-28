class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int ans = 0;
    vector<int> count(26);

    for (const char c : chars)
      ++count[c - 'a'];

    for (const string& word : words) {
      vector<int> tempCount(count);
      for (const char c : word)
        if (--tempCount[c - 'a'] < 0) {
          ans -= word.length();
          break;
        }
      ans += word.length();
    }

    return ans;
  }
};
