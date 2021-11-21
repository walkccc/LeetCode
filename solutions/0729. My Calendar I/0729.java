class MyCalendar {
  public boolean book(int start, int end) {
    for (int[] book : books)
      if (Math.max(book[0], start) < Math.min(book[1], end))
        return false;
    books.add(new int[] {start, end});
    return true;
  }

  private List<int[]> books = new ArrayList<>();
}
