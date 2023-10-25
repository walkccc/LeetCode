class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:
    stack = []  # Unpaired '(' indices
    chars = [c for c in s]

    for i, c in enumerate(chars):
      if c == '(':
        stack.append(i)  # Record unpaired '(' index
      elif c == ')':
        if stack:
          stack.pop()  # Find a pair
        else:
          chars[i] = '*'  # Mark unpaired ')' as '*'

    # Mark unpaired '(' as '*'
    while stack:
      chars[stack.pop()] = '*'

    return ''.join(chars).replace('*', '')
