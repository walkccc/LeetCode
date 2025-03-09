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
  public int[] maximizeXor(int[] nums, int[][] queries) {
    int[] ans = new int[queries.length];
    Arrays.fill(ans, -1);
    final int maxNumInNums = Arrays.stream(nums).max().getAsInt();
    final int maxNumInQuery = Arrays.stream(queries).mapToInt(query -> query[0]).max().getAsInt();
    final int maxBit = (int) (Math.log(Math.max(maxNumInNums, maxNumInQuery)) / Math.log(2));
    BitTrie bitTrie = new BitTrie(maxBit);

    Arrays.sort(nums);

    int i = 0; // nums' index
    for (IndexedQuery indexedQuery : getIndexedQueries(queries)) {
      final int queryIndex = indexedQuery.queryIndex;
      final int x = indexedQuery.x;
      final int m = indexedQuery.m;
      while (i < nums.length && nums[i] <= m)
        bitTrie.insert(nums[i++]);
      if (i > 0 && nums[i - 1] <= m)
        ans[queryIndex] = bitTrie.getMaxXor(x);
    }

    return ans;
  }

  private record IndexedQuery(int queryIndex, int x, int m){};

  private IndexedQuery[] getIndexedQueries(int[][] queries) {
    IndexedQuery[] indexedQueries = new IndexedQuery[queries.length];
    for (int i = 0; i < queries.length; ++i)
      indexedQueries[i] = new IndexedQuery(i, queries[i][0], queries[i][1]);
    Arrays.sort(indexedQueries, (a, b) -> Integer.compare(a.m, b.m));
    return indexedQueries;
  }
}
