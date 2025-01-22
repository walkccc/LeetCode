struct Cell {
  int val = 0;
  unordered_map<int, int> posCount;  // {pos: count}
};

class Excel {
 public:
  Excel(int height, char width)
      : width(width), sheet(height, vector<Cell>(width)) {}

  void set(int row, char column, int val) {
    getCell(row, column) = {val, {}};
  }

  int get(int row, char column) {
    const Cell& cell = getCell(row, column);
    if (cell.posCount.empty())
      return cell.val;

    int val = 0;
    for (const auto& [pos, count] : cell.posCount)
      val += get(pos / width + 1, pos % width + 'A') * count;
    return val;
  }

  int sum(int row, char column, vector<string> numbers) {
    getCell(row, column).posCount = parse(numbers);
    return get(row, column);
  }

 private:
  int width;
  vector<vector<Cell>> sheet;

  Cell& getCell(int row, char column) {
    return sheet[row - 1][column - 'A'];
  }

  unordered_map<int, int> parse(const vector<string>& numbers) {
    unordered_map<int, int> count;
    for (const string& s : numbers) {
      const auto [startRow, startCol, endRow, endCol] = parse(s);
      for (int i = startRow - 1; i < endRow; ++i)
        for (int j = startCol - 'A'; j < endCol - 'A' + 1; ++j)
          ++count[i * width + j];
    }
    return count;
  }

  tuple<int, char, int, char> parse(const string& s) {
    if (s.find(':') == string::npos)
      return {stoi(s.substr(1)), s[0], stoi(s.substr(1)), s[0]};

    const int colonIndex = s.find_first_of(':');
    const string& l = s.substr(0, colonIndex);
    const string& r = s.substr(colonIndex + 1);
    return {stoi(l.substr(1)), l[0], stoi(r.substr(1)), r[0]};
  }
};
