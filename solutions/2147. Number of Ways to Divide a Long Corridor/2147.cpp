class Solution {
 public:
  int numberOfWays(string corridor) {
    constexpr int kMod = 1'000'000'007;
    long ans = 1;
    int prevSeat = -1;
    int numSeats = 0;

    for (int i = 0; i < corridor.length(); ++i) {
      if (corridor[i] == 'S') {
        if (++numSeats > 2 && numSeats & 1)
          ans = ans * (i - prevSeat) % kMod;
        prevSeat = i;
      }
    }

    return numSeats > 1 && numSeats % 2 == 0 ? ans : 0;
  }
};
