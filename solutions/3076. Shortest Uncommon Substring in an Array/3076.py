class Solution:
  def shortestSubstrings(self, arr: list[str]) -> list[str]:
    ans = []
    count = collections.Counter()

    def getSubstrings(s: str) -> Iterator[str]:
      for i in range(len(s)):
        for j in range(i + 1, len(s) + 1):
          yield s[i:j]

    def add(s: str) -> None:
      """Adds all substrings of s to `count`."""
      for sub in getSubstrings(s):
        count[sub] += 1

    def remove(s: str) -> None:
      """Removes all substrings of s from `count`."""
      for sub in getSubstrings(s):
        count[sub] -= 1

    def getMinSub(s: str) -> str:
      minSub = ''
      for sub in getSubstrings(s):
        if count[sub] > 0:
          continue
        if minSub == ('' or
                      len(sub) < len(minSub) or
                      len(sub) == len(minSub) and sub < minSub):
          minSub = sub
      return minSub

    for s in arr:
      add(s)

    for s in arr:
      remove(s)
      ans.append(getMinSub(s))
      add(s)

    return ans
