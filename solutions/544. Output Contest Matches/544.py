class Solution:
  def findContestMatch(self, n: int) -> str:
    def generateMatches(matches: list[str]) -> str:
      if len(matches) == 1:
        return matches[0]

      nextMatches = []

      for i in range(len(matches) // 2):
        nextMatches.append(
            '(' + matches[i] + ',' + matches[len(matches) - 1 - i] + ')')

      return generateMatches(nextMatches)

    return generateMatches([str(i + 1) for i in range(n)])
