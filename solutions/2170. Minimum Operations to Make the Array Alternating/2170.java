class T {
  public Map<Integer, Integer> count = new HashMap<>();
  public int max = 0;
  public int secondMax = 0;
  public int maxFreq = 0;
  public int secondMaxFreq = 0;
}

class Solution {
  public int minimumOperations(int[] nums) {
    T[] ts = new T[2];
    ts[0] = new T();
    ts[1] = new T();

    for (int i = 0; i < nums.length; ++i) {
      T t = ts[i & 1];
      t.count.merge(nums[i], 1, Integer::sum);
      final int freq = t.count.get(nums[i]);
      if (freq > t.maxFreq) {
        t.maxFreq = freq;
        t.max = nums[i];
      } else if (freq > t.secondMaxFreq) {
        t.secondMaxFreq = freq;
        t.secondMax = nums[i];
      }
    }

    if (ts[0].max == ts[1].max)
      return nums.length -
          Math.max(ts[0].maxFreq + ts[1].secondMaxFreq, ts[1].maxFreq + ts[0].secondMaxFreq);
    return nums.length - (ts[0].maxFreq + ts[1].maxFreq);
  }
}
