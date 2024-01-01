class Solution {
 public:
  long long matrixSumQueries(int n, vector<vector<int>>& queries) {
    long long ans = 0;
    // seen[0] := row, seen[1] := col
    vector<vector<bool>> seen(2, vector<bool>(n));
    // notSet[0] = row, notSet[1] := col
    vector<int> notSet(2, n);

    // Later queries dominate.
    for (int i = queries.size() - 1; i >= 0; --i) {
      const int type = queries[i][0];
      const int index = queries[i][1];
      const int val = queries[i][2];
      if (!seen[type][index]) {
        ans += val * notSet[type ^ 1];
        seen[type][index] = true;
        --notSet[type];
      }
    }

    return ans;
  }
};
