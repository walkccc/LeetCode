class Solution {
 public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    vector<int> mem(1 << bikes.size(), INT_MAX);
    return assignBikes(workers, bikes, 0, 0, mem);
  }

 private:
  // Returns the minimum Manhattan distances to assign bikes to
  // workers[workerIndex..n), where `used` is the bitmask of the used bikes.
  int assignBikes(const vector<vector<int>>& workers,
                  const vector<vector<int>>& bikes, int workerIndex, int used,
                  vector<int>& mem) {
    if (workerIndex == workers.size())
      return 0;
    if (mem[used] != INT_MAX)
      return mem[used];

    for (int bikeIndex = 0; bikeIndex < bikes.size(); ++bikeIndex)
      if ((used >> bikeIndex & 1) == 0)
        mem[used] =
            min(mem[used], dist(workers[workerIndex], bikes[bikeIndex]) +
                               assignBikes(workers, bikes, workerIndex + 1,
                                           used | 1 << bikeIndex, mem));

    return mem[used];
  }

  int dist(const vector<int>& p1, const vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};
