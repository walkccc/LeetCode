class Solution {
 public:
  vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> arr(n);
    int sameColors = 0;

    for (const vector<int>& query : queries) {
      const int i = query[0];
      const int color = query[1];
      if (i + 1 < n) {
        if (arr[i + 1] > 0 && arr[i + 1] == arr[i])
          --sameColors;
        if (arr[i + 1] == color)
          ++sameColors;
      }
      if (i > 0) {
        if (arr[i - 1] > 0 && arr[i - 1] == arr[i])
          --sameColors;
        if (arr[i - 1] == color)
          ++sameColors;
      }
      arr[i] = color;
      ans.push_back(sameColors);
    }

    return ans;
  }
};
