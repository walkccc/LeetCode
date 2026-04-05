class Solution {
 public:
  vector<int> transformArray(vector<int>& arr) {
    if (arr.size() < 3)
      return arr;

    vector<int> ans(arr.size());

    while (ans != arr) {
      ans = arr;
      for (int i = 1; i < arr.size() - 1; ++i) {
        if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])
          ++arr[i];
        else if (ans[i - 1] < ans[i] && ans[i] > ans[i + 1])
          --arr[i];
      }
    }

    return ans;
  }
};
