class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = collections.defaultdict(TrieNode)
    self.isWord = False


class Solution:
  def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
    ans = []
    root = TrieNode()

    for word in words:
      node: TrieNode = root
      for c in word:
        node = node.children.setdefault(c, TrieNode())
      node.isWord = True

    # Scan each text[i..j].
    for i in range(len(text)):
      node: TrieNode = root
      for j in range(i, len(text)):
        c = text[j]
        if c not in node.children:
          break
        node = node.children[c]
        if node.isWord:
          ans.append([i, j])

    return ans
