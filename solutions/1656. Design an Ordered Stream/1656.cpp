class OrderedStream {
 public:
  OrderedStream(int n) : values(n) {}

  vector<string> insert(int idKey, string value) {
    --idKey;  // Converts to 0-indexed.
    values[idKey] = value;
    if (idKey > i)
      return {};
    while (i < values.size() && !values[i].empty())
      ++i;
    return vector<string>{values.begin() + idKey, values.begin() + i};
  }

 private:
  vector<string> values;
  int i = 0;  // values' index (0-indexed)
};
