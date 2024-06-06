class Solution {
 public:
  int numWays(string s) {
    constexpr int kMod = 1'000'000'007;
    const int ones = ranges::count(s, '1');
    if (ones % 3 != 0)
      return 0;
    if (ones == 0) {
      const long n = s.size();
      return (n - 1) * (n - 2) / 2 % kMod;
    }

    int s1End = -1;
    int s2Start = -1;
    int s2End = -1;
    int s3Start = -1;
    int onesSoFar = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '1')
        ++onesSoFar;
      if (s1End == -1 && onesSoFar == ones / 3)
        s1End = i;
      else if (s2Start == -1 && onesSoFar == ones / 3 + 1)
        s2Start = i;
      if (s2End == -1 && onesSoFar == ones / 3 * 2)
        s2End = i;
      else if (s3Start == -1 && onesSoFar == ones / 3 * 2 + 1)
        s3Start = i;
    }

    return static_cast<long>(s2Start - s1End) * (s3Start - s2End) % kMod;
  }
};
