class Solution {
 public:
  bool isIdealPermutation(vector<int>& A) {
    int maxi = -1;  // the most likely to be greater than A[i + 2]

    for (int i = 0; i + 2 < A.size(); ++i) {
      maxi = max(maxi, A[i]);
      if (maxi > A[i + 2])
        return false;
    }

    return true;
  }
};
