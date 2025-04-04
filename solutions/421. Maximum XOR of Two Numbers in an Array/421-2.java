class TrieNode {
  public TrieNode[] children = new TrieNode[2];
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
    }
  }

  public int getMaxXor(int num) {
    int maxXor = 0;
    TrieNode node = root;
    for (int i = maxBit; i >= 0; --i) {
      final int bit = (int) (num >> i & 1);
      final int toggleBit = bit ^ 1;
      if (node.children[toggleBit] != null) {
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
  public int findMaximumXOR(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    if (maxNum == 0)
      return 0;
    final int maxBit = (int) (Math.log(maxNum) / Math.log(2));
    int ans = 0;
    BitTrie bitTrie = new BitTrie(maxBit);

    for (final int num : nums) {
      ans = Math.max(ans, bitTrie.getMaxXor(num));
      bitTrie.insert(num);
    }

    return ans;
  }
}
