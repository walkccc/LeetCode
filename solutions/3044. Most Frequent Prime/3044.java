class Solution {
  public int mostFrequentPrime(int[][] mat) {
    final int[][] dirs = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    final int m = mat.length;
    final int n = mat[0].length;
    int ans = -1;
    int maxFreq = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int[] dir : dirs) {
          int num = 0;
          int x = i;
          int y = j;
          while (0 <= x && x < m && 0 <= y && y < n) {
            num = num * 10 + mat[x][y];
            if (num > 10 && isPrime(num))
              count.merge(num, 1, Integer::sum);
            x += dir[0];
            y += dir[1];
          }
        }

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int prime = entry.getKey();
      final int freq = entry.getValue();
      if (freq > maxFreq) {
        ans = prime;
        maxFreq = freq;
      } else if (freq == maxFreq) {
        ans = Math.max(ans, prime);
      }
    }

    return ans;
  }

  private boolean isPrime(int num) {
    for (int i = 2; i < (int) Math.sqrt(num) + 1; ++i)
      if (num % i == 0)
        return false;
    return true;
  }
}
