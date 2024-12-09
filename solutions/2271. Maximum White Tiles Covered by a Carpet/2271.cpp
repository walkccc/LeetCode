class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    if (ranges::any_of(tiles, [&](const auto& tile) {
      return tile[1] - tile[0] + 1 >= carpetLen;
    }))
      return carpetLen;

    int ans = 0;
    vector<int> starts;
    vector<int> prefix(tiles.size() + 1);

    ranges::sort(tiles);

    for (const vector<int>& tile : tiles)
      starts.push_back(tile[0]);

    for (int i = 0; i < tiles.size(); ++i) {
      const int length = tiles[i][1] - tiles[i][0] + 1;
      prefix[i + 1] = prefix[i] + length;
    }

    for (int i = 0; i < tiles.size(); ++i) {
      const int s = tiles[i][0];
      const int carpetEnd = s + carpetLen - 1;
      const int endIndex =
          ranges::upper_bound(starts, carpetEnd) - starts.begin() - 1;
      const int notCover = max(0, tiles[endIndex][1] - carpetEnd);
      ans = max(ans, prefix[endIndex + 1] - prefix[i] - notCover);
    }

    return ans;
  }
};
