class Solution {
  public int[] threeEqualParts(int[] arr) {
    int ones = 0;

    for (final int a : arr)
      if (a == 1)
        ++ones;

    if (ones == 0)
      return new int[] {0, arr.length - 1};
    if (ones % 3 != 0)
      return new int[] {-1, -1};

    int k = ones / 3;
    int i = 0;
    int j = 0;
    int first = 0;
    int second = 0;
    int third = 0;

    for (i = 0; i < arr.length; ++i)
      if (arr[i] == 1) {
        first = i;
        break;
      }

    int gapOnes = k;

    for (j = i + 1; j < arr.length; ++j)
      if (arr[j] == 1 && --gapOnes == 0) {
        second = j;
        break;
      }

    gapOnes = k;

    for (i = j + 1; i < arr.length; ++i)
      if (arr[i] == 1 && --gapOnes == 0) {
        third = i;
        break;
      }

    while (third < arr.length && arr[first] == arr[second] && arr[second] == arr[third]) {
      ++first;
      ++second;
      ++third;
    }

    if (third == arr.length)
      return new int[] {first - 1, second};
    return new int[] {-1, -1};
  }
}
