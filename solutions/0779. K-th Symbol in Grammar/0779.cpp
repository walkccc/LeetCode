class Solution {
 public:
  int kthGrammar(int N, int K) {
    if (N == 1)
      return 0;
    if (K & 1)
      return kthGrammar(N - 1, (K + 1) / 2) != 0;  // left node
    return kthGrammar(N - 1, K / 2) == 0;          // right node
  }
};
