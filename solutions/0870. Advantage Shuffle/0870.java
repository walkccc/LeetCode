class Solution {
  public int[] advantageCount(int[] nums1, int[] nums2) {
    TreeMap<Integer, Integer> map = new TreeMap<>();

    for (final int num : nums1)
      map.merge(num, 1, Integer::sum);

    for (int i = 0; i < nums2.length; i++) {
      Integer key = map.higherKey(nums2[i]);
      if (key == null)
        key = map.firstKey();
      map.put(key, map.get(key) - 1);
      if (map.get(key) == 0)
        map.remove(key);
      nums1[i] = key;
    }

    return nums1;
  }
}
