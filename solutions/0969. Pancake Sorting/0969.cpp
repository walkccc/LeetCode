class Solution {
 public:
  vector<int> pancakeSort(vector<int>& A) {
    vector<int> ans;

    for (int target = A.size(); target >= 1; --target) {
      int index = find(A, target);
      reverse(begin(A), begin(A) + index + 1);
      reverse(begin(A), begin(A) + target);
      ans.push_back(index + 1);
      ans.push_back(target);
    }

    return ans;
  }

 private:
  int find(vector<int>& A, int target) {
    for (int i = 0; i < A.size(); ++i)
      if (A[i] == target)
        return i;
    throw;
  }
};
