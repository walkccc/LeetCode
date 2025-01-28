class Solution {
 public:
  int superpalindromesInRange(string left, string right) {
    int ans = 0;
    const long l = stoll(left);
    const long r = stoll(right);

    for (long i = sqrt(l); i * i <= r;) {
      const long palindrome = nextPalindrome(i);
      const long squared = palindrome * palindrome;
      if (squared <= r && isPalindrome(squared))
        ++ans;
      i = palindrome + 1;
    }

    return ans;
  }

 private:
  long nextPalindrome(int num) {
    const string s = to_string(num);
    const int n = s.length();
    string half = s.substr(0, (n + 1) / 2);
    string reversedHalf = reversed(half.substr(0, n / 2));
    const long candidate = stoll(half + reversedHalf);
    if (candidate >= num)
      return candidate;
    half = to_string(stoll(half) + 1);
    reversedHalf = reversed(half.substr(0, n / 2));
    return stoll(half + reversedHalf);
  }

  string reversed(const string& s) {
    return {s.rbegin(), s.rend()};
  }

  bool isPalindrome(long num) {
    const string s = to_string(num);
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};
