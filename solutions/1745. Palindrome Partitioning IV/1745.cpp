class Solution {
 public:
  bool checkPartitioning(string s) {
    const int n = s.length();
    vector<vector<int>> mem(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j + 1 < n; ++j)
        if (isPalindrome(s, 0, i, mem) &&      //
            isPalindrome(s, i + 1, j, mem) &&  //
            isPalindrome(s, j + 1, n - 1, mem))
          return true;

    return false;
  }

 private:
  // Returns true if s[i..j] is a palindrome.
  // Returns false if s[i..j] is not a palindrome.
  bool isPalindrome(const string& s, int i, int j, vector<vector<int>>& mem) {
    if (i > j)
      return true;
    if (mem[i][j] != -1)
      return mem[i][j];
    if (s[i] == s[j])
      return mem[i][j] = isPalindrome(s, i + 1, j - 1, mem);
    return mem[i][j] = false;
  }
};
