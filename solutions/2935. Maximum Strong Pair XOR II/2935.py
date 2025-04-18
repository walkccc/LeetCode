class TrieNode:
  def __init__(self):
    self.children: list[TrieNode | None] = [None] * 2
    self.mn = math.inf
    self.mx = -math.inf


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
      node.mn = min(node.mn, num)
      node.mx = max(node.mx, num)

  def getMaxXor(self, x: int) -> int:
    """Returns max(x ^ y) where |x - y| <= min(x, y).

    If x <= y, |x - y| <= min(x, y) can be written as y - x <= x.
    So, y <= 2 * x.
    """
    maxXor = 0
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = x >> i & 1
      toggleBit = bit ^ 1
      # If `node.children[toggleBit].mx > x`, it means there's a number in the
      # node that satisfies the condition to ensure that x <= y among x and y.
      # If `node.children[toggleBit].mn <= 2 * x`, it means there's a number in
      # the node that satisfies the condition for a valid y.
      if (node.children[toggleBit] and
          node.children[toggleBit].mx > x and
              node.children[toggleBit].mn <= 2 * x):
        maxXor = maxXor | 1 << i
        node = node.children[toggleBit]
      elif node.children[bit]:
        node = node.children[bit]
      else:  # There's nothing in the Bit Trie.
        return 0
    return maxXor


class Solution:
  # Same as 2932. Maximum Strong Pair XOR I
  def maximumStrongPairXor(self, nums: list[int]) -> int:
    maxNum = max(nums)
    maxBit = int(math.log2(maxNum))
    bitTrie = BitTrie(maxBit)

    for num in nums:
      bitTrie.insert(num)

    return max(bitTrie.getMaxXor(num) for num in nums)
