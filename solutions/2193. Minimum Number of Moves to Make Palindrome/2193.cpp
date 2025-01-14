class Solution {
 public:
  int minMovesToMakePalindrome(string s) {
    int ans = 0;

    while (s.length() > 1) {
      // Greedily match the last digit.
      const int i = s.find(s.back());
      if (i == s.length() - 1) {
        // s[i] is the middle letter.
        ans += i / 2;
      } else {
        s.erase(i, 1);
        ans += i;  // Swap the matched letter to the left.
      }
      s.pop_back();
    }

    return ans;
  }
};
