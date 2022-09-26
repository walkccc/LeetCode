class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    const int n = A.size();
    vector<int> ans(n);
    int i = n - 1;

    for (int l = 0, r = n - 1; l <= r;)
      if (abs(A[l]) > abs(A[r]))
        ans[i--] = A[l] * A[l++];
      else
        ans[i--] = A[r] * A[r--];

    return ans;
  }
};
