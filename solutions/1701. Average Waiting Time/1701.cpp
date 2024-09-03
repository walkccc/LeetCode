class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double wait = 0;
    double curr = 0;

    for (const vector<int>& c : customers) {
      curr = max(curr, 1.0 * c[0]) + c[1];
      wait += curr - c[0];
    }

    return 1.0 * wait / customers.size();
  }
};
