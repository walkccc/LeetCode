class Solution {
  public int[] sortJumbled(int[] mapping, int[] nums) {
    int[] ans = new int[nums.length];
    List<int[]> A = new ArrayList<>(); // (mapped, index, num)

    for (int i = 0; i < nums.length; ++i)
      A.add(new int[] {getMapped(nums[i], mapping), i, nums[i]});

    Collections.sort(
        A, (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));
    return A.stream().mapToInt(a -> a[2]).toArray();
  }

  private int getMapped(int num, int[] mapping) {
    StringBuilder sb = new StringBuilder();
    for (final char c : String.valueOf(num).toCharArray())
      sb.append(mapping[c - '0']);
    return Integer.parseInt(sb.toString());
  }
}
