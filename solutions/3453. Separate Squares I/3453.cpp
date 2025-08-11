class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    const double halfArea = accumulate(squares.begin(), squares.end(), 0.0,
                                       [](double sum, vector<int>& square) {
      return sum + static_cast<long>(square[2]) * square[2];
    }) / 2;
    vector<tuple<int, bool, int>> events;

    for (const vector<int>& square : squares) {
      const int y = square[1];
      const int l = square[2];
      events.push_back({y, true, l});       // start of square
      events.push_back({y + l, false, l});  // end of square
    }

    ranges::sort(events);

    double area = 0;
    int width = 0;
    int prevY = 0;

    for (const auto& [y, isStart, l] : events) {
      double areaGain = width * static_cast<long>(y - prevY);
      if (area + areaGain >= halfArea)
        return prevY + (halfArea - area) / width;
      area += areaGain;
      width += isStart ? l : -l;
      prevY = y;
    }

    throw;
  }
};
