class Solution {
 public:
  bool backspaceCompare(const string& S, const string& T) {
    for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0;
         --i, --j) {
      for (int backspace = 0; i >= 0 && (S[i] == '#' || backspace); --i)
        backspace += S[i] == '#' ? 1 : -1;
      for (int backspace = 0; j >= 0 && (T[j] == '#' || backspace); --j)
        backspace += T[j] == '#' ? 1 : -1;
      if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
      if (i < 0 && j >= 0 && T[j] != '#') return false;
      if (j < 0 && i >= 0 && S[i] != '#') return false;
    }

    return true;
  }
};