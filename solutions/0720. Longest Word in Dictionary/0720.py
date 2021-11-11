class Solution:
  def longestWord(self, words: List[str]) -> str:
    def dfs(node: dict) -> str:
      ans = node['word'] if 'word' in node else ''

      for child in node:
        if 'word' in node[child] and len(node[child]['word']) > 0:
          childWord = dfs(node[child])
          if len(childWord) > len(ans) or (len(childWord) == len(ans) and childWord < ans):
            ans = childWord

      return ans

    self.root = {}

    for word in words:
      node = self.root
      for c in word:
        if c not in node:
          node[c] = {}
        node = node[c]
      node['word'] = word

    return dfs(self.root)
