class Solution {
 public:
  string longestSubsequenceRepeatedK(string s, int k) {
    string ans;
    vector<int> count(26);
    vector<char> possibleChars;
    queue<string> q{{""}};  // store subseqs, length grows by 1 each time

    for (const char c : s)
      ++count[c - 'a'];

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c - 'a'] >= k)
        possibleChars.push_back(c);

    while (!q.empty()) {
      const string currSubseq = q.front();
      q.pop();
      if (currSubseq.length() * k > s.length())
        return ans;
      for (const char c : possibleChars) {
        const string& newSubseq = currSubseq + c;
        if (isSubsequence(newSubseq, s, k)) {
          q.push(newSubseq);
          ans = newSubseq;
        }
      }
    }

    return ans;
  }

 private:
  bool isSubsequence(const string& subseq, string& s, int k) {
    int i = 0;  // subseq's index
    for (const char c : s)
      if (c == subseq[i])
        if (++i == subseq.length()) {
          if (--k == 0)
            return true;
          i = 0;
        }
    return false;
  }
};
