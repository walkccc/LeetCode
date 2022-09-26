class Solution {
 public:
  int countVowelSubstrings(string word) {
    return countVowelSubstringsAtMost(word, 5) -
           countVowelSubstringsAtMost(word, 4);
  }

 private:
  int countVowelSubstringsAtMost(const string& s, int goal) {
    int ans = 0;
    int k = goal;
    vector<int> count(26);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (string("aeiou").find(s[r]) != string::npos) {  // fresh start
        l = r + 1;
        k = goal;
        count = vector<int>(26);
        continue;
      }
      if (++count[s[r] - 'a'] == 1)
        --k;
      while (k == -1)
        if (--count[s[l++] - 'a'] == 0)
          ++k;
      ans += r - l + 1;  // s[l..r], s[l + 1..r], ..., s[r]
    }

    return ans;
  }
};
