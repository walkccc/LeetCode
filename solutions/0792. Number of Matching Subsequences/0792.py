class Solution:
  def numMatchingSubseq(self, S: str, words: List[str]) -> int:
    def insert(word: str) -> None:
      node = self.root
      for c in word:
        if c not in node:
          node[c] = {'count': 0}
        node = node[c]
      node['count'] += 1

    def dfs(S: str, s: int, node: dict) -> int:
      ans = node['count'] if 'count' in node else 0

      if s >= len(S):
        return ans

      for c in string.ascii_lowercase:
        if c in node:
          try:
            index = S.index(c, s)
            ans += dfs(S, index + 1, node[c])
          except ValueError:
            continue

      return ans

    self.root = {}

    for word in words:
      insert(word)

    return dfs(S, 0, self.root)
