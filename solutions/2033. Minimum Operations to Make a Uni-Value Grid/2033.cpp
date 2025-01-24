class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> A;
    for (const vector<int>& row : grid)
      A.insert(A.end(), row.begin(), row.end());
    if (ranges::any_of(A, [&](int a) { return (a - A[0]) % x; }))
      return -1;

    int ans = 0;

    nth_element(A.begin(), A.begin() + A.size() / 2, A.end());

    for (const int a : A)
      ans += abs(a - A[A.size() / 2]) / x;

    return ans;
  }
};
