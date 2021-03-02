class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& A,
                                  vector<vector<int>>& queries) {
    vector<int> ans;
    int sum = accumulate(begin(A), end(A), 0,
                         [](int a, int b) { return a + (b % 2 == 0 ? b : 0); });

    for (vector<int>& query : queries) {
      if (A[query[1]] % 2 == 0)
        sum -= A[query[1]];
      A[query[1]] += query[0];
      if (A[query[1]] % 2 == 0)
        sum += A[query[1]];
      ans.push_back(sum);
    }

    return ans;
  }
};
