class Solution {
 public:
  int largestPalindrome(int n) {
    if (n == 1)
      return 9;

    constexpr int kMod = 1337;
    const int upper = pow(10, n) - 1;
    const int lower = pow(10, n - 1) - 1;

    for (int i = upper; i > lower; --i) {
      const long cand = getPalindromeCandidate(i);
      for (long j = upper; j * j >= cand; --j)
        if (cand % j == 0)
          return cand % kMod;
    }

    throw;
  }

 private:
  long getPalindromeCandidate(int i) {
    string reversed = to_string(i);
    ranges::reverse(reversed);
    return stol(to_string(i) + reversed);
  }
};
