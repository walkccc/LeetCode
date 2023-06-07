class Solution {
 public:
  long long makeSimilar(vector<int>& nums, vector<int>& target) {
    long long ans = 0;
    vector<vector<int>> A(2);  // A[0] := even nums, A[1] := odd nums
    vector<vector<int>> B(2);  // B[0] := even target, B[1] := odd nums

    for (const int num : nums)
      A[num % 2].push_back(num);

    for (const int num : target)
      B[num % 2].push_back(num);

    sort(begin(A[0]), end(A[0]));
    sort(begin(A[1]), end(A[1]));
    sort(begin(B[0]), end(B[0]));
    sort(begin(B[1]), end(B[1]));

    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < A[i].size(); ++j)
        ans += abs(A[i][j] - B[i][j]) / 2;

    return ans / 2;
  }
};
