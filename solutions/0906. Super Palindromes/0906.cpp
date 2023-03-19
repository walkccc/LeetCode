class Solution {
 public:
  int superpalindromesInRange(string left, string right) {
    int ans = 0;
    long long l = stoll(left);
    long long r = stoll(right);

    for (long long i = sqrt(l); i * i <= r;) {
      long long palindrome = nextPalindrome(i);
      long long squared = palindrome * palindrome;
      if (squared <= r && isPalindrome(squared))
        ++ans;
      i = palindrome + 1;
    }

    return ans;
  }

 private:
  long long nextPalindrome(int num) {
    const string s = to_string(num);
    const int n = s.length();
    string half = s.substr(0, (n + 1) / 2);
    string reversedHalf = reversed(half.substr(0, n / 2));
    const long long candidate = stoll(half + reversedHalf);
    if (candidate >= num)
      return candidate;

    half = to_string(stoll(half) + 1);
    reversedHalf = reversed(half.substr(0, n / 2));
    return stoll(half + reversedHalf);
  }

  string reversed(const string& s) {
    return {rbegin(s), rend(s)};
  }

  bool isPalindrome(long long num) {
    const string s = to_string(num);
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
      if (s[l++] != s[r--])
        return false;

    return true;
  }
};
