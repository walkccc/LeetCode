class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    const int n = arr.size();

    int ans = 0;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    vector<int> minFromBack(n);
    vector<int> maxFromFront(n);

    for (int i = n - 1; i >= 0; --i)
      minFromBack[i] = mini = min(mini, arr[i]);

    for (int i = 0; i < n; ++i)
      maxFromFront[i] = maxi = max(maxi, arr[i]);

    for (int i = 0; i + 1 < n; ++i)
      if (maxFromFront[i] <= minFromBack[i + 1])
        ++ans;

    return ans + 1;
  }
};