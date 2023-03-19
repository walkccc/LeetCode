class Solution:
  def getHappyString(self, n: int, k: int) -> str:
    nextLetters = {'a': 'bc', 'b': 'ac', 'c': 'ab'}
    q = collections.deque(['a', 'b', 'c'])

    while len(q[0]) != n:
      u = q.popleft()
      for nextLetter in nextLetters[u[-1]]:
        q.append(u + nextLetter)

    return '' if len(q) < k else q[k - 1]
