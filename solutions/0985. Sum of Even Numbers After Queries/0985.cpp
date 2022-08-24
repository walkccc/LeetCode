class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& A,
                                  vector<vector<int>>& queries) {
    vector<int> ans;
    int sum = accumulate(begin(A), end(A), 0,
                         [](int a, int b) { return a + (b % 2 == 0 ? b : 0); });

    for (const auto& q : queries) {
      if (A[q[1]] % 2 == 0)
        sum -= A[q[1]];
      A[q[1]] += q[0];
      if (A[q[1]] % 2 == 0)
        sum += A[q[1]];
      ans.push_back(sum);
    }

    return ans;
  }
};
