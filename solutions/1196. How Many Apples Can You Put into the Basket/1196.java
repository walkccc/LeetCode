class Solution {
  public int maxNumberOfApples(int[] weight) {
    int sum = 0;

    Arrays.sort(weight);

    for (int i = 0; i < weight.length; ++i) {
      sum += weight[i];
      if (sum > 5000)
        return i;
    }

    return weight.length;
  }
}
