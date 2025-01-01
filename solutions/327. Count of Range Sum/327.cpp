class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    const int n = nums.size();
    int ans = 0;
    vector<long> prefix{0};

    for (int i = 0; i < n; ++i)
      prefix.push_back(prefix.back() + nums[i]);

    mergeSort(prefix, 0, n, lower, upper, ans);
    return ans;
  }

 private:
  void mergeSort(vector<long>& prefix, int l, int r, int lower, int upper,
                 int& ans) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(prefix, l, m, lower, upper, ans);
    mergeSort(prefix, m + 1, r, lower, upper, ans);
    merge(prefix, l, m, r, lower, upper, ans);
  }

  void merge(vector<long>& prefix, int l, int m, int r, int lower, int upper,
             int& ans) {
    int lo = m + 1;  // the first index s.t. prefix[lo] - prefix[i] >= lower
    int hi = m + 1;  // the first index s.t. prefix[hi] - prefix[i] > upper

    // For each index i in range [l, m], add hi - lo to `ans`.
    for (int i = l; i <= m; ++i) {
      while (lo <= r && prefix[lo] - prefix[i] < lower)
        ++lo;
      while (hi <= r && prefix[hi] - prefix[i] <= upper)
        ++hi;
      ans += hi - lo;
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

    // Put the possible remaining left part into the sorted array.
    while (i <= m)
      sorted[k++] = prefix[i++];

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = prefix[j++];

    copy(sorted.begin(), sorted.end(), prefix.begin() + l);
  }
};
