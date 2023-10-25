class Solution {
 public:
  string getSmallestString(int n, int k) {
    string ans;

    for (int i = 0; i < n; ++i) {
      const int remainingLetters = n - i - 1;
      const int rank = max(1, k - remainingLetters * 26);
      ans += 'a' + rank - 1;
      k -= rank;
    }

    return ans;
  }
};
