class Solution {
 public:
  int findBestValue(vector<int>& arr, int target) {
    const int n = arr.size();
    const double err = 1e-9;

    int prefix = 0;

    sort(begin(arr), end(arr));

    for (int i = 0; i < n; ++i) {
      int ans = round((target - prefix - err) / (double)(n - i));
      if (ans <= arr[i])
        return ans;
      prefix += arr[i];
    }

    return arr.back();
  }
};
