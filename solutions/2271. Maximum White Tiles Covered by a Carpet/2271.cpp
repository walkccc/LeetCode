class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    if (any_of(begin(tiles), end(tiles), [&](const auto& tile) {
          return tile[1] - tile[0] + 1 >= carpetLen;
        }))
      return carpetLen;

    int ans = 0;
    vector<int> starts;
    vector<int> prefix(tiles.size() + 1);

    sort(begin(tiles), end(tiles));

    for (const auto& tile : tiles)
      starts.push_back(tile[0]);

    for (int i = 0; i < tiles.size(); ++i) {
      const int length = tiles[i][1] - tiles[i][0] + 1;
      prefix[i + 1] = prefix[i] + length;
    }

    for (int i = 0; i < tiles.size(); ++i) {
      const int s = tiles[i][0];
      const int carpetEnd = s + carpetLen - 1;
      const int endIndex = upper_bound(begin(starts), end(starts), carpetEnd) -
                           begin(starts) - 1;
      const int notCover = max(0, tiles[endIndex][1] - carpetEnd);
      ans = max(ans, prefix[endIndex + 1] - prefix[i] - notCover);
    }

    return ans;
  }
};
