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

    Collections.sort(letterLogs, Comparator.comparing((String[] letterLog) -> letterLog[1])
                                     .thenComparing((String[] letterLog) -> letterLog[0]));

    for (String[] letterLog : letterLogs)
      ans.add(letterLog[0] + " " + letterLog[1]);

    for (final String digitLog : digitLogs)
      ans.add(digitLog);

    return ans.toArray(new String[0]);
  }
}
