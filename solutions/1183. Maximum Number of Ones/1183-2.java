class Solution {
  public int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    int ans = 0;
    List<Integer> subCount = new ArrayList<>();

    for (int i = 0; i < sideLength; ++i)
      for (int j = 0; j < sideLength; ++j)
        subCount.add(getCount(width, i, sideLength) * getCount(height, j, sideLength));

    Collections.sort(subCount, Collections.reverseOrder());

    for (int i = 0; i < maxOnes; ++i)
      ans += subCount.get(i);

    return ans;
  }

  private int getCount(int length, int index, int sideLength) {
    return (length - index - 1) / sideLength + 1;
  }
}
