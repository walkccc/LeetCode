class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    int ans = 0;
    vector<int> hist(mat[0].size());

    for (const vector<int>& row : mat) {
      for (int i = 0; i < row.size(); ++i)
        hist[i] = row[i] == 0 ? 0 : hist[i] + 1;
      ans += count(hist);
    }

    return ans;
  }

 private:
  int count(const vector<int>& hist) {
    // submatrices[i] := the number of submatrices, where the i-th column is the
    // right border
    vector<int> submatrices(hist.size());
    stack<int> stack;

    for (int i = 0; i < hist.size(); ++i) {
      while (!stack.empty() && hist[stack.top()] >= hist[i])
        stack.pop();
      if (!stack.empty()) {
        const int prevIndex = stack.top();
        submatrices[i] = submatrices[prevIndex] + hist[i] * (i - prevIndex);
      } else {
        submatrices[i] = hist[i] * (i + 1);
      }
      stack.push(i);
    }

    return accumulate(submatrices.begin(), submatrices.end(), 0);
  }
};
