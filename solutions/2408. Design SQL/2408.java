class SQL {
  public SQL(List<String> names, List<Integer> columns) {}

  public void insertRow(String name, List<String> row) {
    db.putIfAbsent(name, new ArrayList<>());
    db.get(name).add(row);
  }

  public void deleteRow(String name, int rowId) {}

  public String selectCell(String name, int rowId, int columnId) {
    return db.get(name).get(rowId - 1).get(columnId - 1);
  }

  private Map<String, List<List<String>>> db = new HashMap<>();
}
