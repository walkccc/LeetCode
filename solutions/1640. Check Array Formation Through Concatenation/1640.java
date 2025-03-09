class Solution {
  public boolean canFormArray(int[] arr, int[][] pieces) {
    List<Integer> concatenated = new ArrayList<>();
    Map<Integer, int[]> startToPiece = new HashMap<>();

    for (int[] piece : pieces)
      startToPiece.put(piece[0], piece);

    for (final int a : arr)
      for (final int num : startToPiece.getOrDefault(a, new int[]))
        concatenated.add(num);

    return Arrays.equals(concatenated.stream().mapToInt(Integer::intValue).toArray(), arr);
  }
}
