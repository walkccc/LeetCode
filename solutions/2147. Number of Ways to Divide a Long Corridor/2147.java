class Solution {
  public int numberOfWays(String corridor) {
    final int kMod = 1_000_000_007;
    long ans = 1;
    int prevSeat = -1;
    int numSeats = 0;

    for (int i = 0; i < corridor.length(); ++i) {
      if (corridor.charAt(i) == 'S') {
        if (++numSeats > 2 && numSeats % 2 == 1)
          ans = ans * (i - prevSeat) % kMod;
        prevSeat = i;
      }
    }

    return numSeats > 1 && numSeats % 2 == 0 ? (int) ans : 0;
  }
}
