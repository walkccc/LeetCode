class Poly:
  def __init__(self, term: str = None, coef: int = None):
    if term and coef:
      self.terms = collections.Counter({term: coef})
    else:
      self.terms = collections.Counter()

  def __add__(self, other):
    for term, coef in other.terms.items():
      self.terms[term] += coef
    return self

  def __sub__(self, other):
    for term, coef in other.terms.items():
      self.terms[term] -= coef
    return self

  def __mul__(self, other):
    res = Poly()
    for a, aCoef in self.terms.items():
      for b, bCoef in other.terms.items():
        res.terms[self._merge(a, b)] += aCoef * bCoef
    return res

  # Def __str__(self):
  #   res = []
  #   for term, coef in self.terms.items():
  #     res.append(term + ': ' + str(coef))
  #   return '{' + ', '.join(res) + '}'

  def toList(self) -> list[str]:
    for term in list(self.terms.keys()):
      if not self.terms[term]:
        del self.terms[term]

    def cmp(term: str) -> tuple:
      # the minimum degree is the last
      if term == '1':
        return (0,)
      var = term.split('*')
      # the maximum degree is the first
      # Break ties by their lexicographic orders.
      return (-len(var), term)

    def concat(term: str) -> str:
      if term == '1':
        return str(self.terms[term])
      return str(self.terms[term]) + '*' + term

    terms = list(self.terms.keys())
    terms.sort(key=cmp)
    return [concat(term) for term in terms]

  def _merge(self, a: str, b: str) -> str:
    if a == '1':
      return b
    if b == '1':
      return a
    res = []
    A = a.split('*')
    B = b.split('*')
    i = 0  # A's index
    j = 0  # B's index
    while i < len(A) and j < len(B):
      if A[i] < B[j]:
        res.append(A[i])
        i += 1
      else:
        res.append(B[j])
        j += 1
    return '*'.join(res + A[i:] + B[j:])


class Solution:
  def basicCalculatorIV(
      self,
      expression: str,
      evalvars: list[str],
      evalints: list[int],
  ) -> list[str]:
    tokens = list(self._getTokens(expression))
    evalMap = {a: b for a, b in zip(evalvars, evalints)}

    for i, token in enumerate(tokens):
      if token in evalMap:
        tokens[i] = str(evalMap[token])

    postfix = self._infixToPostfix(tokens)
    return self._evaluate(postfix).toList()

  def _getTokens(self, s: str) -> Iterator[str]:
    i = 0
    for j, c in enumerate(s):
      if c == ' ':
        if i < j:
          yield s[i:j]
        i = j + 1
      elif c in '()+-*':
        if i < j:
          yield s[i:j]
        yield c
        i = j + 1
    if i < len(s):
      yield s[i:]

  def _infixToPostfix(self, tokens: list[str]) -> list[str]:
    postfix = []
    ops = []

    def precedes(prevOp: str, currOp: str) -> bool:
      if prevOp == '(':
        return False
      return prevOp == '*' or currOp in '+-'

    for token in tokens:
      if token == '(':
        ops.append(token)
      elif token == ')':
        while ops[-1] != '(':
          postfix.append(ops.pop())
        ops.pop()
      elif token in '+-*':  # isOperator(token)
        while ops and precedes(ops[-1], token):
          postfix.append(ops.pop())
        ops.append(token)
      else:  # isOperand(token)
        postfix.append(token)
    return postfix + ops[::-1]

  def _evaluate(self, postfix: list[str]) -> Poly:
    polys: list[Poly] = []
    for token in postfix:
      if token in '+-*':
        b = polys.pop()
        a = polys.pop()
        if token == '+':
          polys.append(a + b)
        elif token == '-':
          polys.append(a - b)
        else:  # token == '*'
          polys.append(a * b)
      elif token.lstrip('-').isnumeric():
        polys.append(Poly("1", int(token)))
      else:
        polys.append(Poly(token, 1))
    return polys[0]
