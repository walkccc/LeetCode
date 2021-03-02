class Solution {
 public:
  int findMinMoves(vector<int>& machines) {
    const int dresses = accumulate(begin(machines), end(machines), 0);
    if (dresses % machines.size() != 0)
      return -1;

    int ans = 0;
    int inout = 0;
    const int average = dresses / machines.size();

    for (const int dress : machines) {
      inout += dress - average;
      ans = max({ans, abs(inout), dress - average});
    }

    return ans;
  }
};
