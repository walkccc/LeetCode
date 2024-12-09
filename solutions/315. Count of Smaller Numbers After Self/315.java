class FenwickTree {
  public FenwickTree(int n) {
    sums = new int[n + 1];
  }

  public void add(int i, int delta) {
    while (i < sums.length) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  public int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

  private int[] sums;

  private static int lowbit(int i) {
    return i & -i;
  }
}

class Solution {
  public List<Integer> countSmaller(int[] nums) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> ranks = getRanks(nums);
    FenwickTree tree = new FenwickTree(ranks.size());

    for (int i = nums.length - 1; i >= 0; --i) {
      final int num = nums[i];
      ans.add(tree.get(ranks.get(num) - 1));
      tree.add(ranks.get(num), 1);
    }

    Collections.reverse(ans);
    return ans;
  }

  private Map<Integer, Integer> getRanks(int[] nums) {
    Map<Integer, Integer> ranks = new HashMap<>();
    SortedSet<Integer> sorted = new TreeSet<>();
    for (final int num : nums)
      sorted.add(num);
    int rank = 0;
    for (Iterator<Integer> it = sorted.iterator(); it.hasNext();)
      ranks.put(it.next(), ++rank);
    return ranks;
  }
}
