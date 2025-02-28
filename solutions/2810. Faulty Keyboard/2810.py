class Solution:
  def finalString(self, s: str) -> str:
    dq = collections.deque()
    inversed = False

    for c in s:
      if c == 'i':
        inversed = not inversed
      elif inversed:
        dq.appendleft(c)
      else:
        dq.append(c)

    return ''.join(reversed(dq)) if inversed else ''.join(dq)
