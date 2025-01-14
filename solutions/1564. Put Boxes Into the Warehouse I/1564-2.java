class Solution {
  public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
    boxes = Arrays.stream(boxes)
                .boxed()
                .sorted(Collections.reverseOrder())
                .mapToInt(Integer::intValue)
                .toArray();
    int i = 0; // warehouse's index

    for (final int box : boxes)
      if (i < warehouse.length && warehouse[i] >= box)
        ++i;

    return i;
  }
}
