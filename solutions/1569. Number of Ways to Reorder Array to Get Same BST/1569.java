class Solution {
  public int numOfWays(int[] nums) {
    comb = generate(nums.length + 1);
    return ways(Arrays.stream(nums).boxed().collect(Collectors.toList())) - 1;
  }

  private static final int kMod = 1_000_000_007;
  // comb[n][k] := C(n, k)
  private List<List<Integer>> comb;

  private int ways(List<Integer> nums) {
    if (nums.size() <= 2)
      return 1;

    List<Integer> left = new ArrayList<>();
    List<Integer> right = new ArrayList<>();

    for (int i = 1; i < nums.size(); ++i)
      if (nums.get(i) < nums.get(0))
        left.add(nums.get(i));
      else
        right.add(nums.get(i));

    long ans = comb.get(nums.size() - 1).get(left.size());
    ans = (ans * ways(left)) % kMod;
    ans = (ans * ways(right)) % kMod;
    return (int) ans;
  }

  // 118. Pascal's Triangle
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> comb = new ArrayList<>();

    for (int i = 0; i < numRows; ++i) {
      Integer[] temp = new Integer[i + 1];
      Arrays.fill(temp, 1);
      comb.add(Arrays.asList(temp));
    }

    for (int i = 2; i < numRows; ++i)
      for (int j = 1; j < comb.get(i).size() - 1; ++j)
        comb.get(i).set(j, (comb.get(i - 1).get(j - 1) + comb.get(i - 1).get(j)) % kMod);

    return comb;
  }
}
