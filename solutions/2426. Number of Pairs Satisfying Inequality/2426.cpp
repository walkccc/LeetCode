class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    // nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
    // nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
    // Define A[i] := nums1[i] - nums2[i] -> A[i] <= A[j] + diff
    vector<int> A;

    for (int i = 0; i < nums1.size(); ++i)
      A.push_back(nums1[i] - nums2[i]);

    long long ans = 0;
    mergeSort(A, 0, A.size() - 1, diff, ans);
    return ans;
  }

 private:
  void mergeSort(vector<int>& A, int l, int r, int diff, long long& ans) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(A, l, m, diff, ans);
    mergeSort(A, m + 1, r, diff, ans);
    merge(A, l, m, r, diff, ans);
  }

  void merge(vector<int>& A, int l, int m, int r, int diff, long long& ans) {
    const int lo = m + 1;
    int hi = m + 1;  // the first index s.t. A[i] <= A[hi] + diff

    // For each index i in the range [l, m], add `r - hi + 1` to the `ans`.
    for (int i = l; i <= m; ++i) {
      while (hi <= r && A[i] > A[hi] + diff)
        ++hi;
      ans += r - hi + 1;
    }

    vector<int> sorted(r - l + 1);
    int k = 0;      // sorted's index
    int i = l;      // left's index
    int j = m + 1;  // right's index

    while (i <= m && j <= r)
      if (A[i] < A[j])
        sorted[k++] = A[i++];
      else
        sorted[k++] = A[j++];

    // Put the possible remaining left part into the sorted array.
    while (i <= m)
      sorted[k++] = A[i++];

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = A[j++];

    copy(sorted.begin(), sorted.end(), A.begin() + l);
  }
};
