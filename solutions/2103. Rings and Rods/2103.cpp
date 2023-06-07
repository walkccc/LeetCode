class Solution {
 public:
  int countPoints(string rings) {
    vector<int> colors(10);

    for (int i = 0; i < rings.length(); i += 2) {
      const int c = rings[i];
      const int color = c == 'R' ? 1 : c == 'G' ? 2 : 4;
      colors[rings[i + 1] - '0'] |= color;
    }

    return count(begin(colors), end(colors), 7);
  }
};
