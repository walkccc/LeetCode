class Solution {
  public int findLucky(int[] arr) {
    int[] count = new int[arr.length + 1];

    for (final int a : arr)
      if (a <= arr.length)
        ++count[a];

    for (int i = arr.length; i >= 1; --i)
      if (count[i] == i)
        return i;

    return -1;
  }
}
