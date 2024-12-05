class Solution {
 public:
  bool canMakeSubsequence(string str1, string str2) {
    int i = 0;  // str2's index

    for (const char c : str1)
      if (c == str2[i] || ('a' + ((c - 'a' + 1) % 26)) == str2[i])
        if (++i == str2.length())
          return true;

    return false;
  }
};
