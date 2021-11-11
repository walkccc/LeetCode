class Solution {
  public List<Integer> countSmaller(int[] nums) {
    List<Integer> ans = new ArrayList<>();
    SortedSet<Integer> sorted = new TreeSet<>();
    Map<Integer, Integer> ranks = new HashMap<>(); // {num: rank}

    for (final int num : nums)
      sorted.add(num);

    FenwickTree tree = new FenwickTree(sorted.size());

    int rank = 0;
    for (Iterator<Integer> it = sorted.iterator(); it.hasNext();)
      ranks.put(it.next(), ++rank);

    for (int i = nums.length - 1; i >= 0; --i) {
      final int num = nums[i];
      ans.add(tree.get(ranks.get(num) - 1));
      tree.update(ranks.get(num), 1);
    }

    Collections.reverse(ans);
    return ans;
  }
}

class FenwickTree {
  public FenwickTree(int n) {
    sums = new int[n + 1];
  }

  public void update(int i, int delta) {
    while (i < sums.length) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  public int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

  private int[] sums;
}
