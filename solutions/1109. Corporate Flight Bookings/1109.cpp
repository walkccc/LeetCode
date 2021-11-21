class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n);

    for (vector<int>& booking : bookings) {
      ans[booking[0] - 1] += booking[2];
      if (booking[1] < n)
        ans[booking[1]] -= booking[2];
    }

    for (int i = 1; i < n; ++i)
      ans[i] += ans[i - 1];

    return ans;
  }
};
