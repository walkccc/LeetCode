class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k;

    while (l < r) {
      const int m = (l + r) / 2;
      if (x - arr[m] <= arr[m + k] - x)
        r = m;
      else
        l = m + 1;
    }

    return {arr.begin() + l, arr.begin() + l + k};
  }
};
