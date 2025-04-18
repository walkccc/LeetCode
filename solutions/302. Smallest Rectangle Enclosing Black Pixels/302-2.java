class Solution {
  public int minArea(char[][] image, int x, int y) {
    this.image = image;
    final int x1 = firstAnyOne(0, x, rowAllZeros);
    final int x2 = firstAllZeros(x + 1, image.length, rowAllZeros);
    final int y1 = firstAnyOne(0, y, colAllZeros);
    final int y2 = firstAllZeros(y + 1, image[0].length, colAllZeros);
    return (x2 - x1) * (y2 - y1);
  }

  private char[][] image;

  private int firstAnyOne(int l, int r, Function<Integer, Boolean> allZeros) {
    while (l < r) {
      final int m = (l + r) / 2;
      if (allZeros.apply(m))
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  private int firstAllZeros(int l, int r, Function<Integer, Boolean> allZeros) {
    while (l < r) {
      final int m = (l + r) / 2;
      if (allZeros.apply(m))
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

  Function<Integer, Boolean> rowAllZeros = new Function<>() {
    public Boolean apply(Integer rowIndex) {
      return new String(image[rowIndex]).chars().allMatch(pixel -> pixel == '0');
    }
  };

  Function<Integer, Boolean> colAllZeros = new Function<>() {
    public Boolean apply(Integer colIndex) {
      for (int i = 0; i < image.length; ++i)
        if (image[i][colIndex] == '1')
          return false;
      return true;
    }
  };
}
