class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int ans = 0;
    int mx = INT_MIN;

    for (int i = 0; i < arr.size(); ++i) {
      mx = max(mx, arr[i]);
      if (mx == i)
        ++ans;
    }

    return ans;
  }
};
