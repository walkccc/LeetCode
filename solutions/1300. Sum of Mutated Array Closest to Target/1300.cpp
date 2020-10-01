class Solution {
 public:
  int findBestValue(vector<int>& arr, int target) {
    const int n = arr.size();
    const double err = 1e-9;

    int prefixSum = 0;

    sort(begin(arr), end(arr));

    for (int i = 0; i < n; ++i) {
      int ans = round((target - prefixSum - err) / (double)(n - i));
      if (ans <= arr[i]) return ans;
      prefixSum += arr[i];
    }

    return arr.back();
  }
};