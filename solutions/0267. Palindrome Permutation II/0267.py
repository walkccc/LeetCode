class Solution:
  def generatePalindromes(self, s: str) -> List[str]:
    # get character occurrence
    count = Counter(s)

    # count odd one
    odd = sum(value & 1 for value in count.values())

    # can't form any palindrome
    if odd > 1:
      return []

    ans = []
    candidates = []
    mid = ''

    # get mid and candidates characters
    for key, value in count.items():
      if value & 1:
        mid += key
      for _ in range(value // 2):
        candidates.append(key)

    # generate all unique palindromes from candidates
    def dfs(used: List[bool], path: List[chr]) -> None:
      if len(path) == len(candidates):
        ans.append(''.join(path) + mid + ''.join(path[::-1]))
        return

      for i, candidate in enumerate(candidates):
        if used[i]:
          continue
        if i > 0 and candidate == candidates[i - 1] and not used[i - 1]:
          continue
        used[i] = True
        path.append(candidate)
        dfs(used, path)
        path.pop()
        used[i] = False

    # backtracking to generate our ans (strings)
    dfs([False] * len(candidates), [])
    return ans
