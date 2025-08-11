class Solution {
 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<int>> mem(locations.size(), vector<int>(fuel + 1, -1));
    return countRoutes(locations, start, finish, fuel, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of ways to reach the `finish` city from the i-th city
  // with `fuel` fuel.
  int countRoutes(const vector<int>& locations, int i, int finish, int fuel,
                  vector<vector<int>>& mem) {
    if (fuel < 0)
      return 0;
    if (mem[i][fuel] != -1)
      return mem[i][fuel];

    int res = i == finish ? 1 : 0;
    for (int j = 0; j < locations.size(); ++j) {
      if (j == i)
        continue;
      res += countRoutes(locations, j, finish,
                         fuel - abs(locations[i] - locations[j]), mem);
      res %= kMod;
    }

    return mem[i][fuel] = res;
  }
};
