class Solution {
 public:
  int minimumSum(int n, int k) {
    // These are the unique pairs that sum up to k:
    // (1, k - 1), (2, k - 2), ..., (ceil(k / 2), floor(k / 2)).
    // Our optimal strategy is to select 1, 2, ..., floor(k / 2), and then
    // choose k, k + 1, ... if necessary, as selecting any number in the range
    // [ceil(k / 2), k - 1] will result in a pair summing up to k.
    const int mid = k / 2;  // floor(k / 2)
    if (n <= mid)
      return trapezoid(1, n);
    return trapezoid(1, mid) + trapezoid(k, k + (n - mid - 1));
  }

 private:
  // Returns sum(a..b).
  int trapezoid(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
  }
};
