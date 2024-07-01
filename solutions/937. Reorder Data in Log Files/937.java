class Solution {
  public String[] reorderLogFiles(String[] logs) {
    List<String> ans = new ArrayList<>();
    List<String> digitLogs = new ArrayList<>();
    List<String[]> letterLogs = new ArrayList<>();

    for (final String log : logs) {
      final int i = log.indexOf(' ');
      if (Character.isDigit(log.charAt(i + 1)))
        digitLogs.add(log);
      else
        letterLogs.add(new String[] {log.substring(0, i), log.substring(i + 1)});
    }

    Collections.sort(letterLogs, new Comparator<String[]>() {
      @Override
      public int compare(String[] l1, String[] l2) {
        return l1[1].compareTo(l2[1]) == 0 ? l1[0].compareTo(l2[0]) : l1[1].compareTo(l2[1]);
      }
    });

    for (String[] letterLog : letterLogs)
      ans.add(letterLog[0] + " " + letterLog[1]);

    for (final String digitLog : digitLogs)
      ans.add(digitLog);

    return ans.toArray(new String[0]);
  }
}
