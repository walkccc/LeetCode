class Solution {
 public:
  int superpalindromesInRange(string L, string R) {
    int ans = 0;
    long long l = stoll(L);
    long long r = stoll(R);

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
    long long candidate = stoll(half + reversedHalf);
    if (candidate >= num)
      return candidate;

    half = to_string(stoll(half) + 1);
    reversedHalf = reversed(half.substr(0, n / 2));
    return stoll(half + reversedHalf);
  }

  string reversed(const string& s) {
    string r = s;
    reverse(begin(r), end(r));
    return r;
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
