class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    // T[i][j] := the number of ways to transform ('a' + i) to ('a' + j)
    const vector<vector<int>> T = getTransformationMatrix();
    const vector poweredT = matrixPow(T, t);
    vector<int> count(26);
    // lengths[i] := the total length of ('a' + i) after t transformations
    vector<long> lengths(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) {
        lengths[j] += static_cast<long>(count[i]) * poweredT[i][j];
        lengths[j] %= kMod;
      }

    return accumulate(lengths.begin(), lengths.end(), 0L) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  vector<vector<int>> getTransformationMatrix() {
    vector<vector<int>> T(26, vector<int>(26));
    // 'z' -> 'ab'
    T[25][0] = 1;
    T[25][1] = 1;
    // 'a' -> 'b', 'b' -> 'c', ..., 'y' -> 'z'
    for (int i = 0; i < 25; ++i)
      T[i][i + 1] = 1;
    return T;
  }

  vector<vector<int>> getIdentityMatrix(int sz) {
    vector<vector<int>> I(sz, vector<int>(sz));
    for (int i = 0; i < sz; ++i)
      I[i][i] = 1;
    return I;
  }

  // Returns A * B.
  vector<vector<int>> matrixMult(const vector<vector<int>>& A,
                                 const vector<vector<int>>& B) {
    const int sz = A.size();
    vector<vector<int>> C(sz, vector<int>(sz));
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k)
          C[i][j] = (C[i][j] + static_cast<long>(A[i][k]) * B[k][j]) % kMod;
    return C;
  }

  // Returns M^n.
  vector<vector<int>> matrixPow(const vector<vector<int>>& M, int n) {
    if (n == 0)
      return getIdentityMatrix(M.size());
    if (n % 2 == 1)
      return matrixMult(M, matrixPow(M, n - 1));
    return matrixPow(matrixMult(M, M), n / 2);
  }
};
