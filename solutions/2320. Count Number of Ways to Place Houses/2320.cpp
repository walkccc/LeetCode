class Solution {
 public:
  int countHousePlacements(int n) {
    constexpr int kMod = 1'000'000'007;
    int house = 1;  // # of ways ending w/ house
    int space = 1;  // # of ways ending w/ space
    int total = house + space;

    for (int i = 2; i <= n; ++i) {
      house = space;
      space = total;
      total = (house + space) % kMod;
    }

    return static_cast<long>(total) * total % kMod;
  }
};
