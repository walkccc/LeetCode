class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    const int m = image.size();
    const int n = image[0].size();
    const int startColor = image[sr][sc];

    vector<vector<bool>> seen(m, vector<bool>(n));

    function<void(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (seen[i][j] || image[i][j] != startColor) return;

      image[i][j] = newColor;
      seen[i][j] = true;

      dfs(i + 1, j);
      dfs(i - 1, j);
      dfs(i, j + 1);
      dfs(i, j - 1);
    };

    dfs(sr, sc);

    return image;
  }
};