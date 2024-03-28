class Solution {
 public:
  int getMinSwaps(string num, int k) {
    string perm = num;

    while (k--)
      next_permutation(perm.begin(), perm.end());

    return countSteps(num, perm);
  }

 private:
  int countSteps(const string& A, string& B) {
    int count = 0;

    for (int i = 0, j = 0; i < A.length(); ++i) {
      j = i;
      while (A[i] != B[j])
        ++j;
      while (i < j) {
        swap(B[j], B[j - 1]);
        --j;
        ++count;
      }
    }

    return count;
  }
};
