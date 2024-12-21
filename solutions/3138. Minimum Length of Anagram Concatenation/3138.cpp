class Solution {
 public:
  int minAnagramLength(string s) {
    const int n = s.length();
    for (int k = 1; k <= n; ++k)
      if (n % k == 0 && canFormAnagram(s, k))
        return k;
    return n;
  }

 private:
  // Returns true if we can concatenate an anagram of length k to s.
  bool canFormAnagram(const string& s, int k) {
    const int n = s.length();
    vector<int> anagramCount(26);
    vector<int> runningCount(26);
    for (int i = 0; i < k; ++i)
      ++anagramCount[s[i] - 'a'];
    for (int i = k; i < n; ++i) {
      ++runningCount[s[i] - 'a'];
      if (i % k == k - 1) {
        if (runningCount != anagramCount)
          return false;
        fill(runningCount.begin(), runningCount.end(), 0);
      }
    }
    return true;
  }
};
