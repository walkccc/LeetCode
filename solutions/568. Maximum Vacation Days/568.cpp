class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    vector<vector<int>> mem(days.size(), vector<int>(days[0].size(), INT_MIN));
    return maxVacationDays(flights, days, 0, 0, mem);
  }

 private:
  // Returns the number of vacations that can be taken from the i-th city and
  // the k-th week.
  int maxVacationDays(const vector<vector<int>>& flights,
                      const vector<vector<int>>& days, int i, int k,
                      vector<vector<int>>& mem) {
    if (k == days[0].size())
      return 0;
    if (mem[i][k] != INT_MIN)
      return mem[i][k];

    // Stay at the j-th city or fly from the i-th city to the j-th city.
    for (int j = 0; j < flights.size(); ++j)
      if (j == i || flights[i][j] == 1)
        mem[i][k] = max(mem[i][k], days[j][k] + maxVacationDays(flights, days,
                                                                j, k + 1, mem));

    return mem[i][k];
  }
};
