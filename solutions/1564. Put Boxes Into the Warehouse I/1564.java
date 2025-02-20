class Solution {
  public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
    int[] realWarehouse = new int[warehouse.length];
    realWarehouse[0] = warehouse[0];

    for (int i = 1; i < warehouse.length; i++)
      realWarehouse[i] = Math.min(realWarehouse[i - 1], warehouse[i]);

    Arrays.sort(boxes);
    int i = 0; // boxes' index
    for (int j = realWarehouse.length - 1; j >= 0; j--)
      if (i < boxes.length && boxes[i] <= realWarehouse[j])
        ++i;

    return i;
  }
}
