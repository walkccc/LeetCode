class Solution {
  public String findDifferentBinaryString(String[] nums) {
    final int bitSize = nums[0].length();
    final int maxNum = 1 << bitSize;
    Set<Integer> numsSet = Arrays.stream(nums)
                               .mapToInt(num -> Integer.parseInt(num, 2))
                               .boxed()
                               .collect(Collectors.toSet());

    for (int num = 0; num < maxNum; ++num)
      if (!numsSet.contains(num))
        return String.format("%" + bitSize + "s", Integer.toBinaryString(num)).replace(' ', '0');

    throw new IllegalArgumentException();
  }
}
