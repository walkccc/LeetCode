class Solution {
 public:
  int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    const int n = arr1.size();
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);

    for (int i = 0; i < n; ++i) {
      a[i] = arr1[i] + arr2[i] + i;
      b[i] = arr1[i] + arr2[i] - i;
      c[i] = arr1[i] - arr2[i] + i;
      d[i] = arr1[i] - arr2[i] - i;
    }

    return max(max(diff(a), diff(b)), max(diff(c), diff(d)));
  }

 private:
  int diff(vector<int>& nums) {
    return ranges::max(nums) - ranges::min(nums);
  }
};
