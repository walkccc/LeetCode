class Solution {
 public:
  vector<int> beautifulArray(int n) {
    vector<int> A(n);
    iota(A.begin(), A.end(), 1);
    divide(A, 0, n - 1, 1);
    return A;
  }

 private:
  void divide(vector<int>& A, int l, int r, int mask) {
    if (l >= r)
      return;
    const int m = partition(A, l, r, mask);
    divide(A, l, m, mask << 1);
    divide(A, m + 1, r, mask << 1);
  }

  int partition(vector<int>& A, int l, int r, int mask) {
    int nextSwapped = l;
    for (int i = l; i <= r; ++i)
      if (A[i] & mask)
        swap(A[i], A[nextSwapped++]);
    return nextSwapped - 1;
  }
};
