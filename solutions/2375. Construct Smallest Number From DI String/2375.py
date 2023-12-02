class Solution:
  def smallestNumber(self, pattern: str) -> str:
    ans = []
    stack = ['1']

    for c in pattern:
      maxSorFar = stack[-1]
      if c == 'I':
        while stack:
          maxSorFar = max(maxSorFar, stack[-1])
          ans.append(stack.pop())
      stack.append(chr(ord(maxSorFar) + 1))

    while stack:
      ans.append(stack.pop())

    return ''.join(ans)
