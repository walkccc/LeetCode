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
  public long goodTriplets(int[] nums1, int[] nums2) {
    final int n = nums1.length;
    long ans = 0;
    Map<Integer, Integer> numToIndex = new HashMap<>();
    int[] arr = new int[n];
    // leftSmaller[i] := the number of arr[j] < arr[i], where 0 <= j < i
    int[] leftSmaller = new int[n];
    // rightLarger[i] := the number of arr[j] > arr[i], where i < j < n
    int[] rightLarger = new int[n];
    FenwickTree tree1 = new FenwickTree(n); // Calculates `leftSmaller`.
    FenwickTree tree2 = new FenwickTree(n); // Calculates `rightLarger`.

    for (int i = 0; i < n; ++i)
      numToIndex.put(nums1[i], i);

    // Remap each number in `nums2` to the according index in `nums1` as `arr`.
    // So the problem is to find the number of increasing tripets in `arr`.
    for (int i = 0; i < n; ++i)
      arr[i] = numToIndex.get(nums2[i]);

    for (int i = 0; i < n; ++i) {
      leftSmaller[i] = tree1.get(arr[i]);
      tree1.add(arr[i] + 1, 1);
    }

    for (int i = n - 1; i >= 0; --i) {
      rightLarger[i] = tree2.get(n) - tree2.get(arr[i]);
      tree2.add(arr[i] + 1, 1);
    }

    for (int i = 0; i < n; ++i)
      ans += (long) leftSmaller[i] * rightLarger[i];

    return ans;
  }
}
