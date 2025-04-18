class Cell {
  public int val = 0;
  public Map<Integer, Integer> posCount = new HashMap<>(); // {pos, count}
  public Cell(int val, Map<Integer, Integer> posCount) {
    this.val = val;
    this.posCount = posCount;
  }
}

class Excel {
  public Excel(int height, char width) {
    this.width = width;
    this.sheet = new Cell[height][width];

    for (int i = 0; i < height; ++i)
      for (int j = 0; j < width; ++j)
        sheet[i][j] = new Cell(0, null);
  }

  public void set(int row, char column, int val) {
    sheet[row - 1][column - 'A'] = new Cell(val, null);
  }

  public int get(int row, char column) {
    Cell cell = sheet[row - 1][column - 'A'];
    if (cell.posCount == null)
      return cell.val;

    int val = 0;
    for (Map.Entry<Integer, Integer> entry : cell.posCount.entrySet()) {
      final int pos = entry.getKey();
      final int count = entry.getValue();
      val += get(pos / width + 1, (char) ((pos % width) + 'A')) * count;
    }
    return val;
  }

  public int sum(int row, char column, String[] numbers) {
    sheet[row - 1][column - 'A'].posCount = parse(numbers);
    return get(row, column);
  }

  private int width;
  private Cell[][] sheet;

  private Map<Integer, Integer> parse(String[] numbers) {
    Map<Integer, Integer> count = new HashMap<>();

    for (final String s : numbers) {
      Pair<String, String> tokens = parse(s);
      final int startRow = Integer.parseInt(tokens.getKey().substring(1));
      final char startCol = tokens.getKey().charAt(0);
      final int endRow = Integer.parseInt(tokens.getValue().substring(1));
      final char endCol = tokens.getValue().charAt(0);
      for (int i = startRow - 1; i < endRow; ++i)
        for (int j = startCol - 'A'; j < endCol - 'A' + 1; ++j)
          count.merge(i * width + j, 1, Integer::sum);
    }

    return count;
  }

  private Pair<String, String> parse(final String s) {
    if (!s.contains(":"))
      return new Pair<>(s, s);

    String[] tokens = s.split(":");
    return new Pair<>(tokens[0], tokens[1]);
  }
}
