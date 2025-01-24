class Solution:
  def minOperationsToFlip(self, expression: str) -> int:
    stack = []  # [(the expression, the cost to toggle the expression)]

    for e in expression:
      if e in '(&|':
        # These aren't expressions, so the cost is meaningless.
        stack.append((e, 0))
        continue
      if e == ')':
        lastPair = stack.pop()
        stack.pop()  # Pop '('.
      else:  # e == '0' or e == '1'
        # Store the '0' or '1'. The cost to change their values is just 1,
        # whether it's changing '0' to '1' or '1' to '0'.
        lastPair = (e, 1)
      if stack and stack[-1][0] in '&|':
        op = stack.pop()[0]
        a, costA = stack.pop()
        b, costB = lastPair
        # Determine the cost to toggle op(a, b).
        if op == '&':
          if a == '0' and b == '0':
            # Change '&' to '|' and a|b to '1'.
            lastPair = ('0', 1 + min(costA, costB))
          elif a == '0' and b == '1':
            # Change '&' to '|'.
            lastPair = ('0', 1)
          elif a == '1' and b == '0':
            # Change '&' to '|'.
            lastPair = ('0', 1)
          else:  # a == '1' and b == '1'
            # Change a|b to '0'.
            lastPair = ('1', min(costA, costB))
        else:  # op == '|'
          if a == '0' and b == '0':
            # Change a|b to '1'.
            lastPair = ('0', min(costA, costB))
          elif a == '0' and b == '1':
            # Change '|' to '&'.
            lastPair = ('1', 1)
          elif a == '1' and b == '0':
            # Change '|' to '&'.
            lastPair = ('1', 1)
          else:  # a == '1' and b == '1'
            # Change '|' to '&' and a|b to '0'.
            lastPair = ('1', 1 + min(costA, costB))
      stack.append(lastPair)

    return stack[-1][1]
