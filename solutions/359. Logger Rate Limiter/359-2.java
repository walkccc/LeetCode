class Logger {
  public boolean shouldPrintMessage(int timestamp, String message) {
    if (timestamp < okTime.getOrDefault(message, 0))
      return false;

    okTime.put(message, timestamp + 10);
    return true;
  }

  private Map<String, Integer> okTime = new HashMap<>(); // {message: ok time}
}
