class Solution {
  public int minimumXORSum(int[] nums1, int[] nums2) {
    int[] mem = new int[1 << nums2.length];
    Arrays.fill(mem, Integer.MAX_VALUE);
    return minimumXORSum(nums1, nums2, 0, mem);
  }

  private int minimumXORSum(int[] nums1, int[] nums2, int mask, int[] mem) {
    final int i = Integer.bitCount(mask);
    if (i == nums1.length)
      return 0;
    if (mem[mask] < Integer.MAX_VALUE)
      return mem[mask];

    for (int j = 0; j < nums2.length; ++j)
      if ((mask >> j & 1) == 0)
        mem[mask] = Math.min(mem[mask], (nums1[i] ^ nums2[j]) +
                                            minimumXORSum(nums1, nums2, mask | 1 << j, mem));

    return mem[mask];
  }
}
