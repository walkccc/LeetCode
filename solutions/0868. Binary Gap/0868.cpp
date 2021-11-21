class Solution {
 public:
  int binaryGap(int n) {
    int ans = 0;

    // d := distance between any two 1's
    // initialized to a reasonable small value
    for (int d = -32; n; n /= 2, ++d)
      if (n & 1) {
        ans = max(ans, d);
        d = 0;
      }

    return ans;
  }
};
