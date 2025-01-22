class Solution {
 public:
  vector<int> prevPermOpt1(vector<int>& arr) {
    const int n = arr.size();
    int l = n - 2;
    int r = n - 1;

    while (l >= 0 && arr[l] <= arr[l + 1])
      l--;
    if (l < 0)
      return arr;
    while (arr[r] >= arr[l] || arr[r] == arr[r - 1])
      r--;
    swap(arr[l], arr[r]);

    return arr;
  }
};
