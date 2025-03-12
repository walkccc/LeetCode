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
  public int[] resultArray(int[] nums) {
    List<Integer> arr1 = new ArrayList<>();
    List<Integer> arr2 = new ArrayList<>();
    Map<Integer, Integer> ranks = getRanks(nums);
    FenwickTree tree1 = new FenwickTree(ranks.size());
    FenwickTree tree2 = new FenwickTree(ranks.size());

    add(nums[0], arr1, tree1, ranks);
    add(nums[1], arr2, tree2, ranks);

    for (int i = 2; i < nums.length; ++i) {
      final int greaterCount1 = arr1.size() - tree1.get(ranks.get(nums[i]));
      final int greaterCount2 = arr2.size() - tree2.get(ranks.get(nums[i]));
      if (greaterCount1 > greaterCount2)
        add(nums[i], arr1, tree1, ranks);
      else if (greaterCount1 < greaterCount2)
        add(nums[i], arr2, tree2, ranks);
      else if (arr1.size() > arr2.size())
        add(nums[i], arr2, tree2, ranks);
      else
        add(nums[i], arr1, tree1, ranks);
    }

    arr1.addAll(arr2);
    return arr1.stream().mapToInt(Integer::intValue).toArray();
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

  private void add(int num, List<Integer> arr, FenwickTree tree, Map<Integer, Integer> ranks) {
    arr.add(num);
    tree.add(ranks.get(num), 1);
  };
}
