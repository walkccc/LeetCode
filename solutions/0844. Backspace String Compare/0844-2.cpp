class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    int i = S.length() - 1;  // S's index
    int j = T.length() - 1;  // T's index

    while (true) {
      // delete chars of S if needed
      int back = 0;
      while (i >= 0 && (S[i] == '#' || back > 0)) {
        back += S[i] == '#' ? 1 : -1;
        --i;
      }
      // delete chars of T if needed
      back = 0;
      while (j >= 0 && (T[j] == '#' || back > 0)) {
        back += T[j] == '#' ? 1 : -1;
        --j;
      }
      if (i >= 0 && j >= 0 && S[i] == T[j]) {
        --i;
        --j;
      } else {
        break;
      }
    }

    return i == -1 && j == -1;
  }
};
