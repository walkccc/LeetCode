class Solution:
  def diffWaysToCompute(self, input: str) -> List[int]:
    ans = []

    for i, c in enumerate(input):
      if c in '+-*':
        left = self.diffWaysToCompute(input[:i])
        right = self.diffWaysToCompute(input[i + 1:])
        for a in left:
          for b in right:
            ans.append(eval(str(a) + c + str(b)))

    return ans or [int(input)]
