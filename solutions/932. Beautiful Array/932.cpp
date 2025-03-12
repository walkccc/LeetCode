class Solution {
 public:
  vector<int> beautifulArray(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    divide(arr, 0, n - 1, 1);
    return arr;
  }

 private:
  void divide(vector<int>& arr, int l, int r, int mask) {
    if (l >= r)
      return;
    const int m = partition(arr, l, r, mask);
    divide(arr, l, m, mask << 1);
    divide(arr, m + 1, r, mask << 1);
  }

  int partition(vector<int>& arr, int l, int r, int mask) {
    int nextSwapped = l;
    for (int i = l; i <= r; ++i)
      if (arr[i] & mask)
        swap(arr[i], arr[nextSwapped++]);
    return nextSwapped - 1;
  }
};
