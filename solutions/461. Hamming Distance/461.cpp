class Solution {
 public:
  int hammingDistance(int x, int y) {
    int ans = 0;

    while (x > 0 || y > 0) {
      ans += (x & 1) ^ (y & 1);
      x >>= 1;
      y >>= 1;
    }

    return ans;
  }
};
