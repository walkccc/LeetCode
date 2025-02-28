class Solution {
 public:
  int minOperations(int n) {
    //     median := median of arr
    //   diffs[i] := median - arr[i] where i <= i <= n / 2
    //        ans := sum(diffs)
    // e.g.
    // n = 5, arr = [1, 3, 5, 7, 9], diffs = [4, 2]
    //        ans = (4 + 2) * 2 / 2 = 6
    // n = 6, arr = [1, 3, 5, 7, 9, 11], diffs = [5, 3, 1]
    //        ans = (5 + 1) * 3 / 2 = 9
    const int halfSize = n / 2;
    const int median = (arr(n) + arr(1)) / 2;
    const int firstDiff = median - arr(1);
    const int lastDiff = median - arr(halfSize);
    return (firstDiff + lastDiff) * halfSize / 2;
  }

 private:
  // Returns the i-th element of `arr`, where 1 <= i <= n.
  int arr(int i) {
    return (i - 1) * 2 + 1;
  }
};
