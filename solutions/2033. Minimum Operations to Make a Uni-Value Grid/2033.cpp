class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> arr;
    for (const vector<int>& row : grid)
      arr.insert(arr.end(), row.begin(), row.end());
    if (ranges::any_of(arr, [&](int a) { return (a - arr[0]) % x; }))
      return -1;

    int ans = 0;

    nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());

    for (const int a : arr)
      ans += abs(a - arr[arr.size() / 2]) / x;

    return ans;
  }
};
