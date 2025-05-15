class OrderedStream {
  public OrderedStream(int n) {
    this.values = new String[n];
  }

  public List<String> insert(int idKey, String value) {
    --idKey; // Converts to 0-indexed
    values[idKey] = value;
    if (idKey > i)
      return new ArrayList<>();
    while (i < values.length && values[i] != null && !values[i].isEmpty())
      i++;
    List<String> res = new ArrayList<>();
    for (int j = idKey; j < i; ++j)
      res.add(values[j]);
    return res;
  }

  private String[] values;
  private int i = 0; // values' index (0-indexed)
}
