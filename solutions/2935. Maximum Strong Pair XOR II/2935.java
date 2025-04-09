class TrieNode {
  public TrieNode[] children = new TrieNode[2];
  public int mn = Integer.MAX_VALUE;
  public int mx = Integer.MIN_VALUE;
}

class BitTrie {
  public BitTrie(int maxBit) {
    this.maxBit = maxBit;
  }

  public void insert(int num) {
    TrieNode node = root;
    for (int i = maxBit; i >= 0; --i) {
      final int bit = (int) (num >> i & 1);
      if (node.children[bit] == null)
        node.children[bit] = new TrieNode();
      node = node.children[bit];
      node.mn = Math.min(node.mn, num);
      node.mx = Math.max(node.mx, num);
    }
  }

  // Returns max(x ^ y), where |x - y| <= min(x, y).
  //
  // If x <= y, |x - y| <= min(x, y) can be written as y - x <= x.
  // So, y <= 2 * x.
  public int getMaxXor(int x) {
    int maxXor = 0;
    TrieNode node = root;
    for (int i = maxBit; i >= 0; --i) {
      final int bit = (int) (x >> i & 1);
      final int toggleBit = bit ^ 1;
      // If `node.children[toggleBit].mx > x`, it means there's a number in the
      // node that satisfies the condition to ensure that x <= y among x and y.
      // If `node.children[toggleBit].mn <= 2 * x`, it means there's a number
      // in the node that satisfies the condition for a valid y.
      if (node.children[toggleBit] != null && node.children[toggleBit].mx > x &&
          node.children[toggleBit].mn <= 2 * x) {
        maxXor = maxXor | 1 << i;
        node = node.children[toggleBit];
      } else if (node.children[bit] != null) {
        node = node.children[bit];
      } else { // There's nothing in the Bit Trie.
        return 0;
      }
    }
    return maxXor;
  }

  private int maxBit;
  private TrieNode root = new TrieNode();
}

class Solution {
  // Same as 2932. Maximum Strong Pair XOR I
  public int maximumStrongPairXor(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    final int maxBit = (int) (Math.log(maxNum) / Math.log(2));
    int ans = 0;
    BitTrie bitTrie = new BitTrie(maxBit);

    for (final int num : nums)
      bitTrie.insert(num);

    for (final int num : nums)
      ans = Math.max(ans, bitTrie.getMaxXor(num));

    return ans;
  }
}
