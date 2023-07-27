class Solution {
 public:
  string nearestPalindromic(string n) {
    const auto& [prevPalindrome, nextPalindrome] = getPalindromes(n);
    return abs(prevPalindrome - stol(n)) <= abs(nextPalindrome - stol(n))
               ? to_string(prevPalindrome)
               : to_string(nextPalindrome);
  }

 private:
  pair<long, long> getPalindromes(const string& s) {
    const long num = stol(s);
    const int n = s.length();
    pair<long, long> palindromes;
    const string& half = s.substr(0, (n + 1) / 2);
    const string& reversedHalf = reversed(half.substr(0, n / 2));
    const long candidate = stol(half + reversedHalf);

    if (candidate < num)
      palindromes.first = candidate;
    else {
      const string& prevHalf = to_string(stol(half) - 1);
      const string& reversedPrevHalf = reversed(prevHalf.substr(0, n / 2));
      if (n % 2 == 0 && stol(prevHalf) == 0)
        palindromes.first = 9;
      else if (n % 2 == 0 && (stol(prevHalf) + 1) % 10 == 0)
        palindromes.first = stol(prevHalf + '9' + reversedPrevHalf);
      else
        palindromes.first = stol(prevHalf + reversedPrevHalf);
    }

    if (candidate > num)
      palindromes.second = candidate;
    else {
      const string& nextHalf = to_string(stol(half) + 1);
      const string& reversedNextHalf = reversed(nextHalf.substr(0, n / 2));
      palindromes.second = stol(nextHalf + reversedNextHalf);
    }

    return palindromes;
  }

  string reversed(const string& s) {
    return {s.rbegin(), s.rend()};
  }
};
