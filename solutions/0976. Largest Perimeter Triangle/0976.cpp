class Solution {
 public:
  int largestPerimeter(vector<int>& A) {
    sort(begin(A), end(A));

    for (int i = A.size() - 1; i > 1; --i)
      if (A[i - 2] + A[i - 1] > A[i])
        return A[i - 2] + A[i - 1] + A[i];

    return 0;
  }
};
