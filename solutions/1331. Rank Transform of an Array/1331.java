class Solution {
  public int[] arrayRankTransform(int[] arr) {
    int[] sortedArr = Arrays.copyOf(arr, arr.length);
    Map<Integer, Integer> rank = new HashMap<>();

    Arrays.sort(sortedArr);

    for (int a : sortedArr)
      rank.putIfAbsent(a, rank.size() + 1);

    for (int i = 0; i < arr.length; ++i)
      arr[i] = rank.get(arr[i]);

    return arr;
  }
}