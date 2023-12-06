class TrieNode:
  def __init__(self):
    self.children: List[Optional[TrieNode]] = [None] * 2


class BitTrie:
  def __init__(self, maxBit: int):
    self.maxBit = maxBit
    self.root = TrieNode()

  def insert(self, num: int) -> None:
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = num >> i & 1
      if not node.children[bit]:
        node.children[bit] = TrieNode()
      node = node.children[bit]

  def getMaxXor(self, num: int) -> int:
    maxXor = 0
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = num >> i & 1
      toggleBit = bit ^ 1
      if node.children[toggleBit]:
        maxXor = maxXor | 1 << i
        node = node.children[toggleBit]
      elif node.children[bit]:
        node = node.children[bit]
      else:  # There's nothing in the Bit Trie.
        return 0
    return maxXor


class Solution:
  def findMaximumXOR(self, nums: List[int]) -> int:
    maxNum = max(nums)
    if maxNum == 0:
      return 0
    maxBit = int(math.log2(maxNum))
    ans = 0
    bitTrie = BitTrie(maxBit)

    for num in nums:
      ans = max(ans, bitTrie.getMaxXor(num))
      bitTrie.insert(num)

    return ans
