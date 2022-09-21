class Solution {
  public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
    int[] ans = new int[queries.length];
    int sum = 0;

    for (int a : A)
      sum += a % 2 == 0 ? a : 0;

    for (int i = 0; i < queries.length; ++i) {
      if (A[queries[i][1]] % 2 == 0)
        sum -= A[queries[i][1]];
      A[queries[i][1]] += queries[i][0];
      if (A[queries[i][1]] % 2 == 0)
        sum += A[queries[i][1]];
      ans[i] = sum;
    }

    return ans;
  }
}
