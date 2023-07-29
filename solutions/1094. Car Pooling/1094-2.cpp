class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int currentPassengers = 0;
    vector<int> timeline(1001);

    for (const vector<int>& trip : trips) {
      const int nPassengers = trip[0];
      const int start = trip[1];
      const int end = trip[2];
      timeline[start] += nPassengers;
      timeline[end] -= nPassengers;
    }

    for (const int passengerChange : timeline) {
      currentPassengers += passengerChange;
      if (currentPassengers > capacity)
        return false;
    }

    return true;
  }
};
