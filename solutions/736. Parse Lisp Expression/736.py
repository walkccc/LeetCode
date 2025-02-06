class Solution:
  def evaluate(self, expression: str) -> int:
    def evaluate(e: str, prevScope: dict) -> int:
      if e[0].isdigit() or e[0] == '-':
        return int(e)
      if e in prevScope:
        return prevScope[e]

      scope = prevScope.copy()
      nextExpression = e[e.index(' ') + 1:-1]
      tokens = parse(nextExpression)

      if e[1] == 'm':  # 'mult'
        return evaluate(tokens[0], scope) * evaluate(tokens[1], scope)
      if e[1] == 'a':  # 'add'
        return evaluate(tokens[0], scope) + evaluate(tokens[1], scope)

      # 'let'
      for i in range(0, len(tokens) - 2, 2):
        scope[tokens[i]] = evaluate(tokens[i + 1], scope)

      return evaluate(tokens[-1], scope)

    def parse(e: str):
      tokens = []
      s = ''
      opened = 0

      for c in e:
        if c == '(':
          opened += 1
        elif c == ')':
          opened -= 1
        if opened == 0 and c == ' ':
          tokens.append(s)
          s = ''
        else:
          s += c

      if len(s) > 0:
        tokens.append(s)
      return tokens

    return evaluate(expression, {})
