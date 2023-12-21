class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (arr[m] >= arr[m + 1])
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
