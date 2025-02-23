class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    int zeros = ranges::count_if(arr, [](int a) { return a == 0; });

    for (int i = arr.size() - 1, j = arr.size() + zeros - 1; i < j; --i, --j) {
      if (j < arr.size())
        arr[j] = arr[i];
      if (arr[i] == 0)
        if (--j < arr.size())
          arr[j] = arr[i];
    }
  }
};
