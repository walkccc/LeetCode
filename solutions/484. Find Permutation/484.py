class Solution:
  def findPermutation(self, s: str) -> list[int]:
    ans = []
    stack = []

    for i, c in enumerate(s):
      stack.append(i + 1)
      if c == 'I':
        while stack:  # Consume all decreasings
          ans.append(stack.pop())
    stack.append(len(s) + 1)

    while stack:
      ans.append(stack.pop())

    return ans
