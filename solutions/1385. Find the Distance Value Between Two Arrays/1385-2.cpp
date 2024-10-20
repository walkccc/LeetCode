class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;

    ranges::sort(arr2);

    for (const int a : arr1)
      if (ranges::upper_bound(arr2, a + d) == ranges::lower_bound(arr2, a - d))
        ++ans;

    return ans;
  }
};
