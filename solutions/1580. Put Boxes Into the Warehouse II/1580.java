class Solution {
  public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
    int l = 0;
    int r = warehouse.length - 1;

    boxes = Arrays.stream(boxes)
                .boxed()
                .sorted(Collections.reverseOrder())
                .mapToInt(Integer::intValue)
                .toArray();

    for (final int box : boxes) {
      if (l > r)
        return warehouse.length;
      if (box <= warehouse[l])
        ++l;
      else if (box <= warehouse[r])
        --r;
    }

    return l + (warehouse.length - r - 1);
  }
}
