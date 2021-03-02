class MajorityChecker {
  public MajorityChecker(int[] arr) {
    map = new HashMap<>();
    for (int i = 0; i < arr.length; ++i) {
      List<Integer> list = map.getOrDefault(arr[i], new ArrayList<>());
      list.add(i);
      map.put(arr[i], list);
    }
  }

  public int query(int left, int right, int threshold) {
    for (int num : map.keySet()) {
      if (map.get(num).size() < threshold)
        continue;
      int l = Collections.binarySearch(map.get(num), left);
      int r = Collections.binarySearch(map.get(num), right + 1);
      if (l < 0)
        l = -l - 1;
      if (r < 0)
        r = -r - 1;
      if (r - l >= threshold)
        return num;
    }

    return -1;
  }

  private Map<Integer, List<Integer>> map;
}
