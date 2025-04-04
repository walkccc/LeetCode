class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int ans = 0;
    int i = 0;  // stations' index
    int curr = startFuel;
    priority_queue<int> maxHeap;

    while (curr < target) {
      // Add all the reachable stops to maxHeap
      while (i < stations.size() && curr >= stations[i][0])
        maxHeap.push(stations[i++][1]);
      if (maxHeap.empty())  // Can't be refueled.
        return -1;
      curr += maxHeap.top(), maxHeap.pop();  // Pop out the largest gas.
      ++ans;                                 // Then, refuel once.
    }

    return ans;
  }
};
