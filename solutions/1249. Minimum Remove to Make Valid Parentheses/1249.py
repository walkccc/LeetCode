class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:
    stack = []  # unpaired '(' indices
    chars = [c for c in s]

    for i, c in enumerate(chars):
      if c == '(':
        stack.append(i)  # Record the unpaired '(' index.
      elif c == ')':
        if stack:
          stack.pop()  # Find a pair
        else:
          chars[i] = '*'  # Mark the unpaired ')' as '*'.

    # Mark the unpaired '(' as '*'.
    while stack:
      chars[stack.pop()] = '*'

    return ''.join(chars).replace('*', '')
