class Spreadsheet {
  public Spreadsheet(int rows) {}

  public void setCell(String cell, int value) {
    spreadsheet.put(cell, value);
  }

  public void resetCell(String cell) {
    spreadsheet.put(cell, 0);
  }

  public int getValue(String formula) {
    final int i = formula.indexOf('+');
    return getToken(formula.substring(1, i)) + getToken(formula.substring(i + 1));
  }

  private Map<String, Integer> spreadsheet = new HashMap<>();

  private int getToken(final String token) {
    return Character.isDigit(token.charAt(0)) ? Integer.parseInt(token)
                                              : spreadsheet.getOrDefault(token, 0);
  }
}
