class Solution {
  public boolean queryString(String S, int N) {
    if (N > 1511)
      return false;

    for (int i = N; i > N / 2; --i)
      if (!S.contains(Integer.toBinaryString(i)))
        return false;

    return true;
  }
}
