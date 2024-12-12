/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *  public:
 *   // Return the width of char ch when fontSize is used.
 *   int getWidth(int fontSize, char ch);
 *
 *   // Return Height of any char when fontSize is used.
 *   int getHeight(int fontSize)
 * };
 */
class Solution {
 public:
  int maxFont(string text, int w, int h, vector<int>& fonts,
              FontInfo fontInfo) {
    vector<int> count(26);

    for (const char c : text)
      ++count[c - 'a'];

    int l = 0;
    int r = fonts.size() - 1;

    while (l < r) {
      const int m = (l + r + 1) / 2;
      if (fontInfo.getHeight(fonts[m]) <= h &&
          getWidthSum(count, fonts[m], fontInfo) <= w)
        l = m;
      else
        r = m - 1;
    }

    return getWidthSum(count, fonts[l], fontInfo) <= w ? fonts[l] : -1;
  }

 private:
  int getWidthSum(const vector<int>& count, int font, FontInfo& fontInfo) {
    int width = 0;
    for (int i = 0; i < 26; ++i)
      width += count[i] * fontInfo.getWidth(font, (char)('a' + i));
    return width;
  }
};
