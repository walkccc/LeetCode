class Solution {
 public:
  int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                            int capacity) {
    ranges::sort(buses);
    ranges::sort(passengers);

    if (passengers.front() > buses.back())
      return buses.back();

    int ans = passengers[0] - 1;
    int i = 0;  // buses' index
    int j = 0;  // passengers' index

    while (i < buses.size()) {
      // Greedily make passengers catch `buses[i]`.
      int arrived = 0;
      while (arrived < capacity && j < passengers.size() &&
             passengers[j] <= buses[i]) {
        if (j > 0 && passengers[j] != passengers[j - 1] + 1)
          ans = passengers[j] - 1;
        ++j;
        ++arrived;
      }
      // There's room for `buses[i]` to carry a passenger arriving at
      // `buses[i]`.
      if (arrived < capacity && j > 0 && passengers[j - 1] != buses[i])
        ans = buses[i];
      ++i;
    }

    return ans;
  }
};
