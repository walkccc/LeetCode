class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    // nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
    // nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
    // Define arr[i] := nums1[i] - nums2[i] -> arr[i] <= arr[j] + diff
    vector<int> arr;

    for (int i = 0; i < nums1.size(); ++i)
      arr.push_back(nums1[i] - nums2[i]);

    long ans = 0;
    mergeSort(arr, 0, arr.size() - 1, diff, ans);
    return ans;
  }

 private:
  void mergeSort(vector<int>& arr, int l, int r, int diff, long& ans) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(arr, l, m, diff, ans);
    mergeSort(arr, m + 1, r, diff, ans);
    merge(arr, l, m, r, diff, ans);
  }

  void merge(vector<int>& arr, int l, int m, int r, int diff, long& ans) {
    const int lo = m + 1;
    int hi = m + 1;  // the first index s.t. arr[i] <= arr[hi] + diff

    // For each index i in the range [l, m], add `r - hi + 1` to `ans`.
    for (int i = l; i <= m; ++i) {
      while (hi <= r && arr[i] > arr[hi] + diff)
        ++hi;
      ans += r - hi + 1;
    }

    vector<int> sorted(r - l + 1);
    int k = 0;      // sorted's index
    int i = l;      // left's index
    int j = m + 1;  // right's index

    while (i <= m && j <= r)
      if (arr[i] < arr[j])
        sorted[k++] = arr[i++];
      else
        sorted[k++] = arr[j++];

    // Put the possible remaining left part into the sorted array.
    while (i <= m)
      sorted[k++] = arr[i++];

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = arr[j++];

    copy(sorted.begin(), sorted.end(), arr.begin() + l);
  }
};
