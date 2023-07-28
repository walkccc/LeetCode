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
      } else { // Nothing in the Bit Trie.
        return 0;
      }
    }
    return maxXor;
  }

  private int maxBit;
  private TrieNode root = new TrieNode();
}

class Solution {
  public int[] maximizeXor(int[] nums, int[][] queries) {
    int[] ans = new int[queries.length];
    Arrays.fill(ans, -1);
    Pair<int[], Integer>[] queryAndIndexes = new Pair[queries.length];

    final int maxNumInNums = Arrays.stream(nums).max().getAsInt();
    final int maxNumInQuery = Arrays.stream(queries).mapToInt(query -> query[0]).max().getAsInt();
    final int maxBit = (int) (Math.log(Math.max(maxNumInNums, maxNumInQuery)) / Math.log(2));
    BitTrie bitTrie = new BitTrie(maxBit);

    for (int i = 0; i < queries.length; ++i)
      queryAndIndexes[i] = new Pair<>(queries[i], i);

    Arrays.sort(nums);
    Arrays.sort(queryAndIndexes, (a, b) -> Integer.compare(a.getKey()[1], b.getKey()[1]));

    int i = 0; // nums' index
    for (Pair<int[], Integer> pair : queryAndIndexes) {
      final int[] query = pair.getKey();
      final int index = pair.getValue();
      final int x = query[0];
      final int m = query[1];
      while (i < nums.length && nums[i] <= m)
        bitTrie.insert(nums[i++]);
      if (i > 0 && nums[i - 1] <= m)
        ans[index] = bitTrie.getMaxXor(x);
    }

    return ans;
  }
}
