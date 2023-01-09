class Solution {
  public int consecutiveNumbersSum(int N) {
    int ans = 0;

    for (int i = 1, triangleNum = i; triangleNum <= N; ++i, triangleNum += i)
      if ((N - triangleNum) % i == 0)
        ++ans;

    return ans;
  }
}
