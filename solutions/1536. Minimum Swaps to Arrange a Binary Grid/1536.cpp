class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    const int n = grid.size();
    int ans = 0;
    // suffixZeros[i] := # of suffix zeros in i-th row
    vector<int> suffixZeros;

    for (const vector<int> row : grid) {
      const auto itLastOne = find(rbegin(row), rend(row), 1);
      const int suffixZeroCount = distance(rbegin(row), itLastOne);
      suffixZeros.push_back(suffixZeroCount);
    }

    for (int i = 0; i < n; ++i) {
      const int neededZeros = n - i - 1;
      // Get the first row w/ suffix zeros >= `neededZeros` in suffixZeros[i:].
      const auto it = find_if(begin(suffixZeros) + i, end(suffixZeros),
                              [&](int count) { return count >= neededZeros; });
      if (it == end(suffixZeros))
        return -1;
      const int j = distance(begin(suffixZeros), it);
      // Move rows[j] to rows[i].
      for (int k = j; k > i; --k)
        suffixZeros[k] = suffixZeros[k - 1];
      ans += j - i;
    }

    return ans;
  }
};
