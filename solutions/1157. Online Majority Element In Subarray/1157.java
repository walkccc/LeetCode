class MajorityChecker {
  public MajorityChecker(int[] arr) {
    A = arr;
    for (int i = 0; i < A.length; ++i) {
      if (!numToIndices.containsKey(A[i]))
        numToIndices.put(A[i], new ArrayList<>());
      numToIndices.get(A[i]).add(i);
    }
  }

  public int query(int left, int right, int threshold) {
    for (int i = 0; i < kTimes; ++i) {
      final int num = A[rand.nextInt(A.length)];
      List<Integer> indices = numToIndices.get(num);
      final int l = firstGreaterEqual(indices, left);
      final int r = firstGreaterEqual(indices, right + 1);
      if (r - l >= threshold)
        return num;
    }

    return -1;
  }

  private static final int kTimes = 20; // 2^kTimes >> A.length
  private int[] A;
  private Map<Integer, List<Integer>> numToIndices = new HashMap<>();
  private Random rand = new Random();

  private int firstGreaterEqual(List<Integer> indices, int target) {
    int index = Collections.binarySearch(indices, target);
    return index < 0 ? -index - 1 : index;
  }
}
