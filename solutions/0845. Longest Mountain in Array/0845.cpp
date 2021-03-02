class Solution {
 public:
  int longestMountain(vector<int>& A) {
    int ans = 0;

    for (int i = 0; i + 1 < A.size();) {
      while (i + 1 < A.size() && A[i] == A[i + 1])
        ++i;

      int increasing = 0;
      int decreasing = 0;

      while (i + 1 < A.size() && A[i] < A[i + 1]) {
        ++increasing;
        ++i;
      }

      while (i + 1 < A.size() && A[i] > A[i + 1]) {
        ++decreasing;
        ++i;
      }

      if (increasing > 0 && decreasing > 0)
        ans = max(ans, increasing + decreasing + 1);
    }

    return ans;
  }
};
