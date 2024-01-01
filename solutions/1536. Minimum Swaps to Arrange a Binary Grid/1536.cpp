class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    const int n = grid.size();
    int ans = 0;
    // suffixZeros[i] := the number of suffix zeros in the i-th row
    vector<int> suffixZeros;

    for (const vector<int> row : grid) {
      const auto itLastOne = find(row.rbegin(), row.rend(), 1);
      const int suffixZeroCount = distance(row.rbegin(), itLastOne);
      suffixZeros.push_back(suffixZeroCount);
    }

    for (int i = 0; i < n; ++i) {
      const int neededZeros = n - i - 1;
      // Get the first row with suffix zeros >= `neededZeros` in
      // suffixZeros[i:..n).
      const auto it = find_if(suffixZeros.begin() + i, suffixZeros.end(),
                              [&](int count) { return count >= neededZeros; });
      if (it == suffixZeros.end())
        return -1;
      const int j = distance(suffixZeros.begin(), it);
      // Move the rows[j] to the rows[i].
      for (int k = j; k > i; --k)
        suffixZeros[k] = suffixZeros[k - 1];
      ans += j - i;
    }

    return ans;
  }
};
