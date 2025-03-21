class Solution {
 public:
  int numOfWays(int n) {
    constexpr int kMod = 1'000'000'007;
    long color2 = 6;  // 121, 131, 212, 232, 313, 323
    long color3 = 6;  // 123, 132, 213, 231, 312, 321

    for (int i = 1; i < n; ++i) {
      const long nextColor2 = color2 * 3 + color3 * 2;
      const long nextColor3 = color2 * 2 + color3 * 2;
      color2 = nextColor2 % kMod;
      color3 = nextColor3 % kMod;
    }

    return (color2 + color3) % kMod;
  }
};
