class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size();

    // find the first index l s.t. nMissing(l) = A[l] - l - 1 >= k
    while (l < r) {
      const int m = (l + r) / 2;
      if (arr[m] - m - 1 >= k)
        r = m;
      else
        l = m + 1;
    }

    // the k-th missing positive
    // = A[l - 1] + k - nMissing(l - 1)
    // = A[l - 1] + k - (A[l - 1] - (l - 1) - 1)
    // = A[l - 1] + k - (A[l - 1] - l)
    // = l + k
    return l + k;
  }
};
