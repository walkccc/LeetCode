class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.isWord = False


class Solution:
  def addBoldTag(self, s: str, words: list[str]) -> str:
    n = len(s)
    ans = []
    # bold[i] := True if s[i] should be bolded
    bold = [0] * n
    root = TrieNode()

    def insert(word: str) -> None:
      node = root
      for c in word:
        node = node.children.setdefault(c, TrieNode())
      node.isWord = True

    def find(s: str, i: int) -> int:
      node = root
      ans = -1
      for j in range(i, len(s)):
        if s[j] not in node.children:
          node.children[s[j]] = TrieNode()
        node = node.children[s[j]]
        if node.isWord:
          ans = j
      return ans

    for word in words:
      insert(word)

    boldEnd = -1  # `s[i..boldEnd]` should be bolded.
    for i in range(n):
      boldEnd = max(boldEnd, find(s, i))
      bold[i] = boldEnd >= i

    # Construct the with bold tags
    i = 0
    while i < n:
      if bold[i]:
        j = i
        while j < n and bold[j]:
          j += 1
        # `s[i..j)` should be bolded.
        ans.append('<b>' + s[i:j] + '</b>')
        i = j
      else:
        ans.append(s[i])
        i += 1

    return ''.join(ans)
