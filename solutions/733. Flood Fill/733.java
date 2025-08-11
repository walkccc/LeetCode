class Solution {
  public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
    boolean[][] seen = new boolean[image.length][image[0].length];
    dfs(image, sr, sc, seen, image[sr][sc], newColor);
    return image;
  }

  private void dfs(int[][] image, int i, int j, boolean[][] seen, int startColor, int newColor) {
    if (i < 0 || i == image.length || j < 0 || j == image[0].length)
      return;
    if (image[i][j] != startColor || seen[i][j])
      return;

    image[i][j] = newColor;
    seen[i][j] = true;

    dfs(image, i + 1, j, seen, startColor, newColor);
    dfs(image, i - 1, j, seen, startColor, newColor);
    dfs(image, i, j + 1, seen, startColor, newColor);
    dfs(image, i, j - 1, seen, startColor, newColor);
  }
}
