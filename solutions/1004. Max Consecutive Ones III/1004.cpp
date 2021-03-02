class Solution {
 public:
  int longestOnes(vector<int>& A, int K) {
    int ans = 0;

    for (int l = 0, r = 0; r < A.size(); ++r) {
      if (A[r] == 0)
        --K;
      while (K < 0)
        if (A[l++] == 0)
          ++K;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
