class Solution {
 public:
  string minimizeStringValue(string s) {
    string ans;
    vector<int> count(26);
    vector<char> letters;

    for (const char c : s)
      if (c != '?')
        ++count[c - 'a'];

    for (const char c : s) {
      if (c != '?')
        continue;
      const char minFreqLetter = getMinFreqLetter(count);
      letters.push_back(minFreqLetter);
      ++count[minFreqLetter - 'a'];
    }

    ranges::sort(letters);
    int i = 0;  // letters' index

    for (const char c : s)
      ans += c == '?' ? letters[i++] : c;

    return ans;
  }

 private:
  char getMinFreqLetter(const vector<int>& count) {
    char minFreqLetter = 'a';
    for (char c = 'b'; c <= 'z'; ++c)
      if (count[c - 'a'] < count[minFreqLetter - 'a'])
        minFreqLetter = c;
    return minFreqLetter;
  }
};
