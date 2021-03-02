class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> ans;
    int min = INT_MAX;

    sort(begin(arr), end(arr));

    for (int i = 0; i + 1 < arr.size(); ++i) {
      int diff = arr[i + 1] - arr[i];
      if (diff < min) {
        min = diff;
        ans.clear();
      }
      if (diff == min)
        ans.push_back({arr[i], arr[i + 1]});
    }

    return ans;
  }
};
