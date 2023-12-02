class TrieNode {
  public TrieNode[] children = new TrieNode[2];
  public int count = 0;
}

class Solution {
  public int countPairs(int[] nums, int low, int high) {
    int ans = 0;

    for (final int num : nums) {
      ans += getCount(num, high + 1) - getCount(num, low);
      insert(num);
    }

    return ans;
  }

  private final int kHeight = 14;
  private TrieNode root = new TrieNode();

  private void insert(int num) {
    TrieNode node = root;
    for (int i = kHeight; i >= 0; --i) {
      final int bit = num >> i & 1;
      if (node.children[bit] == null)
        node.children[bit] = new TrieNode();
      node = node.children[bit];
      ++node.count;
    }
  }

  // Returns the number of numbers < limit.
  private int getCount(int num, int limit) {
    int count = 0;
    TrieNode node = root;
    for (int i = kHeight; i >= 0; --i) {
      final int bit = num >> i & 1;
      final int bitLimit = ((limit >> i) & 1);
      if (bitLimit == 1) {
        if (node.children[bit] != null)
          count += node.children[bit].count;
        node = node.children[bit ^ 1];
      } else {
        node = node.children[bit];
      }
      if (node == null)
        break;
    }
    return count;
  }
}
