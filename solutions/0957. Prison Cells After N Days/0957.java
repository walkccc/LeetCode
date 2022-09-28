class Solution {
  public int[] prisonAfterNDays(int[] cells, int N) {
    int[] firstDayCells = new int[cells.length];
    int[] nextDayCells = new int[cells.length];

    for (int day = 0; N-- > 0; cells = nextDayCells.clone(), ++day) {
      for (int i = 1; i + 1 < cells.length; ++i)
        nextDayCells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
      if (day == 0)
        firstDayCells = nextDayCells.clone();
      else if (Arrays.equals(nextDayCells, firstDayCells))
        N %= day;
    }

    return cells;
  }
}
