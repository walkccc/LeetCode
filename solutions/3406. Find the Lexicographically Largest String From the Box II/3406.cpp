class Solution {
 public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1)
      return word;
    const string s = lastSubstring(word);
    const size_t sz = word.length() - numFriends + 1;
    return s.substr(0, min(s.length(), sz));
  }

 private:
  // Same as 1163. Last Substring in Lexicographical Order
  string lastSubstring(string s) {
    int i = 0;
    int j = 1;
    int k = 0;

    while (j + k < s.length())
      if (s[i + k] == s[j + k]) {
        ++k;
      } else if (s[i + k] > s[j + k]) {
        // Skip s[j..j + k) and advance to s[j + k + 1] to find a possible
        // lexicographically larger substring since s[i..i + k) == s[j..j + k)
        // and s[i + k] > s[j + k).
        j = j + k + 1;
        k = 0;
      } else {
        // Skip s[i..i + k) and advance to s[i + k + 1] or s[j] to find a
        // possible lexicographically larger substring since
        // s[i..i + k) == s[j..j + k) and s[i + k] < s[j + k).
        // Note that it's unnecessary to explore s[i + k + 1..j) if
        // i + k + 1 < j since they are already explored by j.
        i = max(i + k + 1, j);
        j = i + 1;
        k = 0;
      }

    return s.substr(i);
  }
};
