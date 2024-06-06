class Solution {
 public:
  string rearrangeString(string s, int k) {
    const int n = s.length();
    string ans;
    vector<int> count(26);
    // valid[i] := the leftmost index ('a' + i) can appear
    vector<int> valid(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int i = 0; i < n; ++i) {
      const char c = getBestLetter(count, valid, i);
      if (c == '*')
        return "";
      ans += c;
      --count[c - 'a'];
      valid[c - 'a'] = i + k;
    }

    return ans;
  }

 private:
  // Returns the valid letter that has the most count.
  char getBestLetter(const vector<int>& count, const vector<int>& valid,
                     int index) {
    int maxCount = -1;
    char bestLetter = '*';

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c - 'a'] > 0 && count[c - 'a'] > maxCount &&
          index >= valid[c - 'a']) {
        bestLetter = c;
        maxCount = count[c - 'a'];
      }

    return bestLetter;
  }
};
