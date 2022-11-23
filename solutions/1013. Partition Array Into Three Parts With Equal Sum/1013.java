class Solution {
  public boolean canThreePartsEqualSum(int[] A) {
    int sum = Arrays.stream(A).sum();
    int prefix = 0;
    int parts = 1;

    for (int a : A) {
      prefix += a;
      if (prefix == sum * parts / 3)
        ++parts;
    }

    return sum % 3 == 0 && parts >= 3;
  }
}
