class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    const int n = arr.size();
    int ans = 0;
    vector<int> maxL(n);  // l[i] := max(arr[0..i])
    vector<int> minR(n);  // r[i] := min(arr[i..n))

    for (int i = 0; i < n; ++i)
      maxL[i] = i == 0 ? arr[i] : max(arr[i], maxL[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      minR[i] = i == n - 1 ? arr[i] : min(arr[i], minR[i + 1]);

    for (int i = 0; i + 1 < n; ++i)
      if (maxL[i] <= minR[i + 1])
        ++ans;

    return ans + 1;
  }
};
