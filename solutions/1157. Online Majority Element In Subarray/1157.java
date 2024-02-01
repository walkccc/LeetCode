class MajorityChecker {
  public MajorityChecker(int[] arr) {
    this.arr = arr;
    for (int i = 0; i < arr.length; ++i) {
      if (!numToIndices.containsKey(arr[i]))
        numToIndices.put(arr[i], new ArrayList<>());
      numToIndices.get(arr[i]).add(i);
    }
  }

  public int query(int left, int right, int threshold) {
    for (int i = 0; i < kTimes; ++i) {
      final int randIndex = rand.nextInt(right - left + 1) + left;
      final int num = arr[randIndex];
      List<Integer> indices = numToIndices.get(num);
      final int l = firstGreaterEqual(indices, left);
      final int r = firstGreaterEqual(indices, right + 1);
      if (r - l >= threshold)
        return num;
    }

    return -1;
  }

  private static final int kTimes = 20; // 2^kTimes >> |arr|
  private int[] arr;
  private Map<Integer, List<Integer>> numToIndices = new HashMap<>();
  private Random rand = new Random();

  private int firstGreaterEqual(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
  }
}
