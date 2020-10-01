class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    string ans;

    // check if a is a subsequence of b
    auto isSubsequence = [](const string& a, const string& b) {
      int i = 0;
      for (const char c : b)
        if (c == a[i])
          ++i;
      return i == a.length();
    };

    for (const string& word : d)
      if (isSubsequence(word, s))
        if (word.length() > ans.length() ||
            word.length() == ans.length() && word.compare(ans) < 0)
          ans = word;

    return ans;
  }
};