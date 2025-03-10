class Solution {
  public int scoreOfStudents(String s, int[] answers) {
    final int n = s.length() / 2 + 1;
    int ans = 0;
    Set<Integer>[][] dp = new Set[n][n];
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        dp[i][j] = new HashSet<>();

    for (int i = 0; i < n; ++i)
      dp[i][i].add(s.charAt(i * 2) - '0');

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        for (int k = i; k < j; ++k) {
          final char op = s.charAt(k * 2 + 1);
          for (final int a : dp[i][k])
            for (final int b : dp[k + 1][j]) {
              final int res = func(op, a, b);
              if (res <= 1000)
                dp[i][j].add(res);
            }
        }
      }

    final int correctAnswer = eval(s);

    for (final int answer : answers)
      count.merge(answer, 1, Integer::sum);

    for (final int answer : count.keySet())
      if (answer == correctAnswer)
        ans += 5 * count.get(answer);
      else if (dp[0][n - 1].contains(answer))
        ans += 2 * count.get(answer);

    return ans;
  }

  private int eval(final String s) {
    int ans = 0;
    int currNum = 0;
    int prevNum = 0;
    char op = '+';

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      if (Character.isDigit(c))
        currNum = currNum * 10 + (c - '0');
      if (!Character.isDigit(c) || i == s.length() - 1) {
        if (op == '+') {
          ans += prevNum;
          prevNum = currNum;
        } else if (op == '*') {
          prevNum = prevNum * currNum;
        }
        op = c;
        currNum = 0;
      }
    }

    return ans + prevNum;
  }

  private int func(char op, int a, int b) {
    if (op == '+')
      return a + b;
    return a * b;
  }
}
