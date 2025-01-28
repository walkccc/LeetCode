class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.word: str | None = None


class Solution:
  def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
    m = len(board)
    n = len(board[0])
    ans = []
    root = TrieNode()

    def insert(word: str) -> None:
      node = root
      for c in word:
        node = node.children.setdefault(c, TrieNode())
      node.word = word

    for word in words:
      insert(word)

    def dfs(i: int, j: int, node: TrieNode) -> None:
      if i < 0 or i == m or j < 0 or j == n:
        return
      if board[i][j] == '*':
        return

      c = board[i][j]
      if c not in node.children:
        return

      child = node.children[c]
      if child.word:
        ans.append(child.word)
        child.word = None

      board[i][j] = '*'
      dfs(i + 1, j, child)
      dfs(i - 1, j, child)
      dfs(i, j + 1, child)
      dfs(i, j - 1, child)
      board[i][j] = c

    for i in range(m):
      for j in range(n):
        dfs(i, j, root)

    return ans
