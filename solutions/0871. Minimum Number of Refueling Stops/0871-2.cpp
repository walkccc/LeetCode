class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int ans = 0;
    int i = 0;  // stations's index
    int curr = startFuel;
    priority_queue<int> maxHeap;

    while (curr < target) {
      // add all reachable stops to maxHeap
      while (i < stations.size() && curr >= stations[i][0])
        maxHeap.push(stations[i++][1]);
      if (maxHeap.empty())  // we can't refuel
        return -1;
      curr += maxHeap.top(), maxHeap.pop();  // pop out the largest gas
      ++ans;                                 // then refuel once
    }

    return ans;
  }
};
