class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    const int n = nums.size();

    int count = 0;
    vector<long> prefix(n + 1);

    for (int i = 0; i < n; ++i)
      prefix[i + 1] += (long)nums[i] + prefix[i];

    mergeSort(prefix, 0, n, lower, upper, count);

    return count;
  }

 private:
  void mergeSort(vector<long>& prefix, int l, int r, int lower, int upper,
                 int& count) {
    if (l >= r)
      return;

    const int m = l + (r - l) / 2;
    mergeSort(prefix, l, m, lower, upper, count);
    mergeSort(prefix, m + 1, r, lower, upper, count);
    merge(prefix, l, m, r, lower, upper, count);
  }

  void merge(vector<long>& prefix, int l, int m, int r, int lower, int upper,
             int& count) {
    int lo = m + 1;  // 1st index s.t. prefix[lo] - prefix[i] >= lower
    int hi = m + 1;  // 1st index s.t. prefix[hi] - prefix[i] > upper

    // for each index i in range [l, m], add hi - lo to count
    for (int i = l; i <= m; ++i) {
      while (lo <= r && prefix[lo] - prefix[i] < lower)
        ++lo;
      while (hi <= r && prefix[hi] - prefix[i] <= upper)
        ++hi;
      count += hi - lo;
    }

    vector<long> sorted(r - l + 1);
    int k = 0;      // sorted's index
    int i = l;      // left's index
    int j = m + 1;  // right's index

    while (i <= m && j <= r)
      if (prefix[i] < prefix[j])
        sorted[k++] = prefix[i++];
      else
        sorted[k++] = prefix[j++];

    // put possible remaining left part to the sorted array
    while (i <= m)
      sorted[k++] = prefix[i++];

    // put possible remaining right part to the sorted array
    while (j <= r)
      sorted[k++] = prefix[j++];

    copy(begin(sorted), end(sorted), begin(prefix) + l);
  }
};
