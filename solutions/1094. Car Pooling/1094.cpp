class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int currentPassengers = 0;
    map<int, int> timeline;

    for (const vector<int>& trip : trips) {
      const int nPassengers = trip[0];
      const int start = trip[1];
      const int end = trip[2];
      timeline[start] += nPassengers;
      timeline[end] -= nPassengers;
    }

    for (const auto [_, passengerChange] : timeline) {
      currentPassengers += passengerChange;
      if (currentPassengers > capacity)
        return false;
    }

    return true;
  }
};
