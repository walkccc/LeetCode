class Solution:
  def scoreOfStudents(self, s: str, answers: List[int]) -> int:
    n = len(s) // 2 + 1
    ans = 0
    func = {'+': operator.add, '*': operator.mul}
    dp = [[set() for j in range(n)] for _ in range(n)]

    for i in range(n):
      dp[i][i].add(int(s[i * 2]))

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        for k in range(i, j):
          op = s[k * 2 + 1]
          for a in dp[i][k]:
            for b in dp[k + 1][j]:
              res = func[op](a, b)
              if res <= 1000:
                dp[i][j].add(res)

    correctAnswer = eval(s)

    for answer, freq in Counter(answers).items():
      if answer == correctAnswer:
        ans += 5 * freq
      elif answer in dp[0][n - 1]:
        ans += 2 * freq

    return ans
