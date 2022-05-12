class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:
    stack = []  # unpaired '(' indices
    chars = [c for c in s]

    for i, c in enumerate(chars):
      if c == '(':
        stack.append(i)  # record unpaired '(' index
      elif c == ')':
        if stack:
          stack.pop()  # find a pair
        else:
          chars[i] = '*'  # mark unpaired ')' as '*'

    # mark unpaired '(' as '*'
    while stack:
      chars[stack.pop()] = '*'

    return ''.join(chars).replace('*', '')
