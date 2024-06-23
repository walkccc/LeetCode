class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3)
      return false;

    int l = 0;
    int r = arr.size() - 1;

    while (l + 1 < arr.size() && arr[l] < arr[l + 1])
      ++l;
    while (r > 0 && arr[r] < arr[r - 1])
      --r;

    return l > 0 && r < arr.size() - 1 && l == r;
  }
};
