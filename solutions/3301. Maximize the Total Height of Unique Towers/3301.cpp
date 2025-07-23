class Solution {
 public:
  long long maximumTotalSum(vector<int>& maximumHeight) {
    long ans = 0;
    int mn = INT_MAX;

    ranges::sort(maximumHeight, greater<>());

    for (const int height : maximumHeight) {
      const int assigned = min(height, mn - 1);
      if (assigned == 0)
        return -1;
      ans += assigned;
      mn = assigned;
    }

    return ans;
  }
};
