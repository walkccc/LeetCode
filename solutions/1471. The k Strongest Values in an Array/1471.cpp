class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    ranges::sort(arr);

    const int n = arr.size();
    const int median = arr[(n - 1) / 2];
    vector<int> ans;

    for (int l = 0, r = n - 1; k > 0; --k)
      if (median - arr[l] > arr[r] - median)
        ans.push_back(arr[l++]);
      else
        ans.push_back(arr[r--]);

    return ans;
  }
};
