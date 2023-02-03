class Solution {
  public int[] threeEqualParts(int[] A) {
    int ones = 0;

    for (int a : A)
      if (a == 1)
        ++ones;

    if (ones == 0)
      return new int[] {0, A.length - 1};
    if (ones % 3 != 0)
      return new int[] {-1, -1};

    int k = ones / 3;
    int i = 0;
    int j = 0;
    int first = 0;
    int second = 0;
    int third = 0;

    for (i = 0; i < A.length; ++i)
      if (A[i] == 1) {
        first = i;
        break;
      }

    int gapOnes = k;

    for (j = i + 1; j < A.length; ++j)
      if (A[j] == 1 && --gapOnes == 0) {
        second = j;
        break;
      }

    gapOnes = k;

    for (i = j + 1; i < A.length; ++i)
      if (A[i] == 1 && --gapOnes == 0) {
        third = i;
        break;
      }

    while (third < A.length && A[first] == A[second] && A[second] == A[third]) {
      ++first;
      ++second;
      ++third;
    }

    if (third == A.length)
      return new int[] {first - 1, second};
    return new int[] {-1, -1};
  }
}
