class Solution {
 public:
  string smallestPalindrome(string s) {
    const int n = s.length();
    const string sortedHalf = getSortedHalf(s);
    return sortedHalf + (n % 2 ? string(1, s[n / 2]) : "") +
           reversed(sortedHalf);
  }

 private:
  string getSortedHalf(const string& s) {
    string half = s.substr(0, s.length() / 2);
    ranges::sort(half);
    return half;
  }

  string reversed(const string& s) {
    return {s.rbegin(), s.rend()};
  }
};
