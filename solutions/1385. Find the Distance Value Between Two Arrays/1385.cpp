class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;

    ranges::sort(arr2);

    for (const int a : arr1) {
      const auto it = lower_bound(begin(arr2), end(arr2), a);
      if ((it == arr2.end() || *it - a > d) &&
          (it == arr2.begin() || a - *prev(it) > d))
        ++ans;
    }

    return ans;
  }
};
