class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    const int n = nums.size();

    int count = 0;
    vector<long> prefixSum(n + 1);

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + (long)nums[i - 1];

    function<void(int, int, int)> merge = [&](int l, int m, int r) {
      int lo = m + 1;  // 1st index s.t. prefixSum[lo] - prefixSum[i] >= lower
      int hi = m + 1;  // 1st index s.t. prefixSum[hi] - prefixSum[i] > upper

      // for each index i in range [l, m], add hi - lo to count
      for (int i = l; i <= m; ++i) {
        while (lo <= r && prefixSum[lo] - prefixSum[i] < lower) ++lo;
        while (hi <= r && prefixSum[hi] - prefixSum[i] <= upper) ++hi;
        count += hi - lo;
      }

      vector<long> sorted(r - l + 1);
      int k = 0;      // point to sorted
      int i = l;      // point to left
      int j = m + 1;  // point to right

      while (i <= m && j <= r)
        if (prefixSum[i] < prefixSum[j])
          sorted[k++] = prefixSum[i++];
        else
          sorted[k++] = prefixSum[j++];

      // put possible remaining left part to the sorted array
      while (i <= m)
        sorted[k++] = prefixSum[i++];

      // put possible remaining right part to the sorted array
      while (j <= r)
        sorted[k++] = prefixSum[j++];

      copy(begin(sorted), end(sorted), begin(prefixSum) + l);
    };

    function<void(int, int)> mergeSort = [&](int l, int r) {
      if (l >= r) return;

      const int m = l + (r - l) / 2;
      mergeSort(l, m);
      mergeSort(m + 1, r);
      merge(l, m, r);
    };

    mergeSort(0, n);

    return count;
  }
};