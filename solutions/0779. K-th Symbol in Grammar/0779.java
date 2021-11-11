class Solution {
  public int kthGrammar(int N, int K) {
    if (N == 1)
      return 0;
    if (K % 2 == 1)
      return kthGrammar(N - 1, (K + 1) / 2) == 0 ? 0 : 1; // left node
    return kthGrammar(N - 1, K / 2) == 0 ? 1 : 0;         // right node
  }
}
