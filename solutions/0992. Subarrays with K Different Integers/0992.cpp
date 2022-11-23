class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    return subarrayWithAtMostKDistinct(A, K) -
           subarrayWithAtMostKDistinct(A, K - 1);
  }

 private:
  int subarrayWithAtMostKDistinct(vector<int>& A, int K) {
    int ans = 0;
    vector<int> count(A.size() + 1);

    for (int l = 0, r = 0; r < A.size(); ++r) {
      if (++count[A[r]] == 1)
        --K;
      while (K == -1)
        if (--count[A[l++]] == 0)
          ++K;
      ans += r - l + 1;  // A[l..r], A[l + 1..r], ..., A[r]
    }

    return ans;
  }
};
