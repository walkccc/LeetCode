class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> A;
    for (const auto& row : grid)
      A.insert(end(A), begin(row), end(row));
    if (any_of(begin(A), end(A), [&](int a) { return (a - A[0]) % x; }))
      return -1;

    int ans = 0;

    nth_element(begin(A), begin(A) + A.size() / 2, end(A));

    for (const int a : A)
      ans += abs(a - A[A.size() / 2]) / x;

    return ans;
  }
};
