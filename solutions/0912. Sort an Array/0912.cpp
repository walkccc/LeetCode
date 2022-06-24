class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void mergeSort(vector<int>& A, int l, int r) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
  }

  void merge(vector<int>& A, int l, int m, int r) {
    vector<int> sorted(r - l + 1);
    int k = 0;      // sorted's index
    int i = l;      // left's index
    int j = m + 1;  // right's index

    while (i <= m && j <= r)
      if (A[i] < A[j])
        sorted[k++] = A[i++];
      else
        sorted[k++] = A[j++];

    // put possible remaining left part to the sorted array
    while (i <= m)
      sorted[k++] = A[i++];

    // put possible remaining right part to the sorted array
    while (j <= r)
      sorted[k++] = A[j++];

    copy(begin(sorted), end(sorted), begin(A) + l);
  }
};
