class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    if (A.size() < 3)
      return false;

    int l = 0;
    int r = A.size() - 1;

    while (l + 1 < A.size() && A[l] < A[l + 1])
      ++l;
    while (r > 0 && A[r] < A[r - 1])
      --r;

    return l > 0 && r < A.size() - 1 && l == r;
  }
};
