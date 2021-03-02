class Logger {
  /**
   * Returns true if the message should be printed in the given timestamp,
   * otherwise returns false. If this method returns false, the message will not
   * be printed. The timestamp is in seconds granularity.
   */
  public boolean shouldPrintMessage(int timestamp, String message) {
    if (timestamp < okTime.getOrDefault(message, 0))
      return false;

    okTime.put(message, timestamp + 10);
    return true;
  }

  private Map<String, Integer> okTime = new HashMap<>(); // {message: ok time}
}
