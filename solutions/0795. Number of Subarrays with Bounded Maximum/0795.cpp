class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int ans = 0;
    int l = -1;
    int r = -1;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] > R)  // Handle reset value
        l = i;
      if (A[i] >= L)  // Handle reset and needed value
        r = i;
      ans += r - l;
    }

    return ans;
  }
};
