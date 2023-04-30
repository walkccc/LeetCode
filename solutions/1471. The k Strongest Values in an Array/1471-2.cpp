class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    const int midIndex = (arr.size() - 1) / 2;
    nth_element(begin(arr), begin(arr) + midIndex, end(arr));
    const int median = arr[midIndex];

    nth_element(begin(arr), begin(arr) + k, end(arr), [&](int a, int b) {
      const int da = abs(a - median);
      const int db = abs(b - median);
      return da == db ? a > b : da > db;
    });

    arr.resize(k);
    return arr;
  }
};
