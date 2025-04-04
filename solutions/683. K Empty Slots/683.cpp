class Solution {
 public:
  int kEmptySlots(vector<int>& bulbs, int k) {
    const int n = bulbs.size();
    int ans = INT_MAX;
    // day[i] := the day when bulbs[i] is turned on
    vector<int> day(n);

    for (int i = 0; i < n; ++i)
      day[bulbs[i] - 1] = i + 1;

    // Find a subarray of day[l..r], where its length is k + 2.
    // For each l < i < r, day[i] > max(day[l], day[r]).
    int l = 0;
    int r = l + k + 1;
    for (int i = 1; r < n; ++i)
      if (i == r) {
        ans = min(ans, max(day[l], day[r]));
        l = i;
        r = i + k + 1;
      } else if (day[i] < max(day[l], day[r])) {
        l = i;
        r = i + k + 1;
      }

    return ans == INT_MAX ? -1 : ans;
  }
};
