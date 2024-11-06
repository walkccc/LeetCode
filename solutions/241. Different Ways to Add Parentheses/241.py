class Solution:
  @functools.lru_cache(None)
  def diffWaysToCompute(self, expression: str) -> list[int]:
    ans = []

    for i, c in enumerate(expression):
      if c in '+-*':
        for a in self.diffWaysToCompute(expression[:i]):
          for b in self.diffWaysToCompute(expression[i + 1:]):
            ans.append(eval(str(a) + c + str(b)))

    return ans or [int(expression)]
