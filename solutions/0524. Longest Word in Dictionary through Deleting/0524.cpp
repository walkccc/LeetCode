class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    string ans;

    for (const string& word : d)
      if (isSubsequence(word, s))
        if (word.length() > ans.length() ||
            word.length() == ans.length() && word.compare(ans) < 0)
          ans = word;

    return ans;
  }

 private:
  // return true if a is a subsequence of b
  bool isSubsequence(const string& a, const string& b) {
    int i = 0;
    for (const char c : b)
      if (i < a.length() && c == a[i])
        ++i;
    return i == a.length();
  };
};
