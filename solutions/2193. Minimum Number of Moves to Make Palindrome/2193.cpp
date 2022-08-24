class Solution {
 public:
  int minMovesToMakePalindrome(string s) {
    int ans = 0;

    while (s.length() > 1) {
      // greedily match the last digit
      const int i = s.find(s.back());
      if (i == s.length() - 1) {
        // s[i] is the middle char
        ans += i / 2;
      } else {
        s.erase(i, 1);
        ans += i;  // swapped the matches char to the left
      }
      s.pop_back();
    }

    return ans;
  }
};
