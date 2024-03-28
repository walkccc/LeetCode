class Solution {
  public long maxPower(int[] stations, int r, int k) {
    long left = Arrays.stream(stations).min().getAsInt();
    long right = Arrays.stream(stations).asLongStream().sum() + k + 1;

    while (left < right) {
      final long mid = (left + right) / 2;
      if (check(stations.clone(), r, k, mid))
        left = mid + 1;
      else
        right = mid;
    }

    return left - 1;
  }

  // Returns true if each city can have at least `minPower`.
  boolean check(int[] stations, int r, int additionalStations, long minPower) {
    final int n = stations.length;
    // Initilaize `power` as the 0-th city's power - stations[r].
    long power = 0;

    for (int i = 0; i < r; ++i)
      power += stations[i];

    for (int i = 0; i < n; ++i) {
      if (i + r < n)
        power += stations[i + r]; // `power` = sum(stations[i - r..i + r]).
      if (power < minPower) {
        final long requiredPower = minPower - power;
        // There're not enough stations to plant.
        if (requiredPower > additionalStations)
          return false;
        // Greedily plant `requiredPower` power stations in the farthest place
        // to cover as many cities as possible.
        stations[Math.min(n - 1, i + r)] += requiredPower;
        additionalStations -= requiredPower;
        power += requiredPower;
      }
      if (i - r >= 0)
        power -= stations[i - r];
    }

    return true;
  }
}
