class Solution {
  public int smallestRepunitDivByK(int K) {
    if (K % 10 != 1 && K % 10 != 3 && K % 10 != 7 && K % 10 != 9)
      return -1;

    Set<Integer> seen = new HashSet<>();
    int N = 0;

    for (int length = 1; length <= K; ++length) {
      N = (N * 10 + 1) % K;
      if (N == 0)
        return length;
      if (seen.contains(N))
        return -1;
      seen.add(N);
    }

    return -1;
  }
}
