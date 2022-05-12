class Solution:
  def deserialize(self, s: str) -> NestedInteger:
    if s[0] != '[':
      return NestedInteger(int(s))

    stack = []

    for i, c in enumerate(s):
      if c == '[':
        stack.append(NestedInteger())
        start = i + 1
      elif c == ',':
        if i > start:
          num = int(s[start:i])
          stack[-1].add(NestedInteger(num))
        start = i + 1
      elif c == ']':
        popped = stack.pop()
        if i > start:
          num = int(s[start:i])
          popped.add(NestedInteger(num))
        if stack:
          stack[-1].add(popped)
        else:
          return popped
        start = i + 1
