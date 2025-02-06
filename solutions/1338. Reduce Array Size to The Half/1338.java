class Solution {
  public int minSetSize(int[] arr) {
    final int n = arr.length;
    int sum = 0;
    Map<Integer, Integer> count = new HashMap<>();
    List<Map.Entry<Integer, Integer>> numAndFreqs = new ArrayList<>();

    for (final int a : arr)
      count.merge(a, 1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet())
      numAndFreqs.add(entry);

    numAndFreqs.sort(Comparator.comparing(Map.Entry<Integer, Integer>::getValue).reversed());

    for (int i = 0; i < numAndFreqs.size(); ++i) {
      sum += numAndFreqs.get(i).getValue();
      if (sum >= n / 2)
        return i + 1;
    }

    throw new IllegalArgumentException();
  }
}
