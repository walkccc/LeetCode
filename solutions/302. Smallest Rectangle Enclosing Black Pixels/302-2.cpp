class Solution {
 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    const int x1 = firstAnyOne(image, 0, x, &rowAllZeros);
    const int x2 = firstAllZeros(image, x + 1, image.size(), &rowAllZeros);
    const int y1 = firstAnyOne(image, 0, y, &colAllZeros);
    const int y2 = firstAllZeros(image, y + 1, image[0].size(), &colAllZeros);
    return (x2 - x1) * (y2 - y1);
  }

 private:
  int firstAnyOne(const vector<vector<char>>& image, int l, int r,
                  function<bool(const vector<vector<char>>&, int)> allZeros) {
    while (l < r) {
      const int m = (l + r) / 2;
      if (allZeros(image, m))
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  int firstAllZeros(const vector<vector<char>>& image, int l, int r,
                    function<bool(const vector<vector<char>>&, int)> allZeros) {
    while (l < r) {
      const int m = (l + r) / 2;
      if (allZeros(image, m))
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

  static bool rowAllZeros(const vector<vector<char>>& image, int rowIndex) {
    return all_of(image[rowIndex].cbegin(), image[rowIndex].cend(),
                  [](int pixel) { return pixel == '0'; });
  }

  static bool colAllZeros(const vector<vector<char>>& image, int colIndex) {
    for (int i = 0; i < image.size(); ++i)
      if (image[i][colIndex] == '1')
        return false;
    return true;
  }
};
