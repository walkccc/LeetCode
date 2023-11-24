class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    dfs(image, sr, sc,
        vector<vector<bool>>(image.size(), vector<bool>(image[0].size())),
        image[sr][sc], newColor);
    return image;
  }

 private:
  void dfs(vector<vector<int>>& image, int i, int j,
           vector<vector<bool>>&& seen, int startColor, int newColor) {
    if (i < 0 || i == image.size() || j < 0 || j == image[0].size())
      return;
    if (image[i][j] != startColor || seen[i][j])
      return;

    image[i][j] = newColor;
    seen[i][j] = true;

    dfs(image, i + 1, j, move(seen), startColor, newColor);
    dfs(image, i - 1, j, move(seen), startColor, newColor);
    dfs(image, i, j + 1, move(seen), startColor, newColor);
    dfs(image, i, j - 1, move(seen), startColor, newColor);
  }
};
