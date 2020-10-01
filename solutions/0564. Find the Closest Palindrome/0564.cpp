class Solution {
 public:
  string nearestPalindromic(string n) {
    const auto& [prevPalindrome, nextPalindrome] = getPalindromes(n);

    return abs(prevPalindrome - stoll(n)) <= abs(nextPalindrome - stoll(n))
               ? to_string(prevPalindrome)
               : to_string(nextPalindrome);
  }

 private:
  pair<long long, long long> getPalindromes(const string& s) {
    const long long num = stoll(s);
    const int n = s.length();

    pair<long long, long long> palindromes;
    const string half = s.substr(0, (n + 1) / 2);
    const string reversedHalf = reversed(half.substr(0, n / 2));
    const long long candidate = stoll(half + reversedHalf);

    if (candidate < num)
      palindromes.first = candidate;
    else {
      const string prevHalf = to_string(stoll(half) - 1);
      const string reversedPrevHalf = reversed(prevHalf.substr(0, n / 2));
      if (n % 2 == 0 && stoll(prevHalf) == 0)
        palindromes.first = 9;
      else if (n % 2 == 0 && (stoll(prevHalf) + 1) % 10 == 0)
        palindromes.first = stoll(prevHalf + '9' + reversedPrevHalf);
      else
        palindromes.first = stoll(prevHalf + reversedPrevHalf);
    }

    if (candidate > num)
      palindromes.second = candidate;
    else {
      const string nextHalf = to_string(stoll(half) + 1);
      const string reversedNextHalf = reversed(nextHalf.substr(0, n / 2));
      palindromes.second = stoll(nextHalf + reversedNextHalf);
    }

    return palindromes;
  }

  string reversed(const string& s) {
    string r = s;
    reverse(begin(r), end(r));
    return r;
  }
};