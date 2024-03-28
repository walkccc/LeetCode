class Solution:
  def parseBoolExpr(self, expression: str) -> bool:
    def dfs(s: int, e: int) -> List[str]:
      if s == e:
        return True if expression[s] == 't' else False

      exps = []
      layer = 0

      for i in range(s, e + 1):
        c = expression[i]
        if layer == 0 and c in '!&|':
          op = c
        elif c == '(':
          layer += 1
          if layer == 1:
            left = i + 1
        elif c == ')':
          layer -= 1
          if layer == 0:
            exps.append(dfs(left, i - 1))
        elif c == ',' and layer == 1:
          exps.append(dfs(left, i - 1))
          left = i + 1

      if op == '|':
        return functools.reduce(lambda x, y: x | y, exps)
      if op == '&':
        return functools.reduce(lambda x, y: x & y, exps)
      if op == '!':
        return not exps[0]

    return dfs(0, len(expression) - 1)
