class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k;

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (x - arr[m] > arr[m + k] - x)
        l = m + 1;
      else
        r = m;
    }

    return {begin(arr) + l, begin(arr) + l + k};
  }
};