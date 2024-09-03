class Solution {
  public int[] platesBetweenCandles(String s, int[][] queries) {
    final int n = s.length();
    int[] ans = new int[queries.length];
    int[] closestLeftCandle = new int[n];
    int[] closestRightCandle = new int[n];
    int[] candleCount = new int[n]; // candleCount[i] := the number of candles in s[0..i]
    int candle = -1;
    int count = 0;

    for (int i = 0; i < n; ++i) {
      if (s.charAt(i) == '|') {
        candle = i;
        ++count;
      }
      closestLeftCandle[i] = candle;
      candleCount[i] = count;
    }

    candle = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (s.charAt(i) == '|')
        candle = i;
      closestRightCandle[i] = candle;
    }

    for (int i = 0; i < queries.length; ++i) {
      final int left = queries[i][0];
      final int right = queries[i][1];
      final int l = closestRightCandle[left];
      final int r = closestLeftCandle[right];
      if (i == -1 || r == -1 || l > r)
        continue;
      final int lengthBetweenCandles = r - l + 1;
      final int numCandles = candleCount[r] - candleCount[l] + 1;
      ans[i] = lengthBetweenCandles - numCandles;
    }

    return ans;
  }
}
