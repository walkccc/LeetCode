class Solution {
  public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
    Arrays.sort(buses);
    Arrays.sort(passengers);

    if (passengers[0] > buses[buses.length - 1])
      return buses[buses.length - 1];

    int ans = passengers[0] - 1;
    int i = 0; // buses' index
    int j = 0; // passengers' index

    while (i < buses.length) {
      // greedily make passengers catch buses[i]
      int arrived = 0;
      while (arrived < capacity && j < passengers.length && passengers[j] <= buses[i]) {
        if (j > 0 && passengers[j] != passengers[j - 1] + 1)
          ans = passengers[j] - 1;
        ++j;
        ++arrived;
      }
      // there's room for buses[i] to carry a passenger arriving at buses[i]
      if (arrived < capacity && j > 0 && passengers[j - 1] != buses[i])
        ans = buses[i];
      ++i;
    }

    return ans;
  }
}
