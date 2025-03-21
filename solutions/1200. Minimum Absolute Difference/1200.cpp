class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> ans;
    int mn = INT_MAX;

    ranges::sort(arr);

    for (int i = 1; i < arr.size(); ++i) {
      const int diff = arr[i] - arr[i - 1];
      if (diff < mn) {
        mn = diff;
        ans.clear();
      }
      if (diff == mn)
        ans.push_back({arr[i - 1], arr[i]});
    }

    return ans;
  }
};
