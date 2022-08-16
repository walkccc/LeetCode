class Solution:
  def minimizeResult(self, expression: str) -> str:
    plusIndex = expression.index('+')
    left = expression[:plusIndex]
    right = expression[plusIndex + 1:]
    ans = ''
    mini = math.inf

    # expression . a * (b + c) * d
    for i in range(len(left)):
      for j in range(len(right)):
        a = 1 if i == 0 else int(left[:i])
        b = int(left[i:])
        c = int(right[0:j + 1])
        d = 1 if j == len(right) - 1 else int(right[j + 1:])
        val = a * (b + c) * d
        if val < mini:
          mini = val
          ans = ('' if i == 0 else str(a)) + \
              '(' + str(b) + '+' + str(c) + ')' + \
                ('' if j == len(right) - 1 else str(d))

    return ans
