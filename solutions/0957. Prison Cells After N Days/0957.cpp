class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<int> firstDayCells;
    vector<int> nextDayCells(cells.size());

    for (int day = 0; N-- > 0; cells = nextDayCells, ++day) {
      for (int i = 1; i + 1 < cells.size(); ++i)
        nextDayCells[i] = cells[i - 1] == cells[i + 1];
      if (day == 0)
        firstDayCells = nextDayCells;
      else if (nextDayCells == firstDayCells)
        N %= day;
    }

    return cells;
  }
};
