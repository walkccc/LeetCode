class Solution:
  def isDecomposable(self, s: str) -> bool:
    twos = 0

    for _, group in itertools.groupby(s):
      groupLength = len(list(group))
      if groupLength % 3 == 1:
        return False
      if groupLength % 3 == 2:
        twos += 1
        if twos > 1:
          return False

    return twos == 1
