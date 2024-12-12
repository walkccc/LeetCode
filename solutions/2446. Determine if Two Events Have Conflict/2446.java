class Solution {
  public boolean haveConflict(String[] event1, String[] event2) {
    return event1[0].compareTo(event2[1]) <= 0 && event2[0].compareTo(event1[1]) <= 0;
  }
}
