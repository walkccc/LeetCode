class Solution {
  public String largestWordCount(String[] messages, String[] senders) {
    final int n = messages.length;
    String ans = "";
    int maxWordsSent = 0;
    Map<String, Integer> count = new HashMap<>(); // {sender, # words sent}

    for (int i = 0; i < n; ++i) {
      final String message = messages[i];
      final String sender = senders[i];
      final int wordsCount = (int) message.chars().filter(c -> c == ' ').count() + 1;
      count.merge(sender, wordsCount, Integer::sum);
      final int numWordsSent = count.get(sender);
      if (numWordsSent > maxWordsSent) {
        ans = sender;
        maxWordsSent = numWordsSent;
      } else if (numWordsSent == maxWordsSent && sender.compareTo(ans) > 0) {
        ans = sender;
      }
    }

    return ans;
  }
}
