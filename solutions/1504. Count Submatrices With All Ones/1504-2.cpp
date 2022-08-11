class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    int ans = 0;
    vector<int> hist(n);

    for (const auto& row : mat) {
      for (int i = 0; i < row.size(); ++i)
        hist[i] = row[i] == 0 ? 0 : hist[i] + 1;
      ans += count(hist);
    }

    return ans;
  }

 private:
  int count(const vector<int>& A) {
    // submatrices[i] := # of submatrices w/ column i as the right border
    vector<int> submatrices(A.size());
    stack<int> stack;

    for (int i = 0; i < A.size(); ++i) {
      while (!stack.empty() && A[stack.top()] >= A[i])
        stack.pop();
      if (!stack.empty()) {
        const int prevIndex = stack.top();
        submatrices[i] = submatrices[prevIndex] + A[i] * (i - prevIndex);
      } else {
        submatrices[i] = A[i] * (i + 1);
      }
      stack.push(i);
    }

    return accumulate(begin(submatrices), end(submatrices), 0);
  }
};
