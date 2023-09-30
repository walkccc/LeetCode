class FrequencyTracker {
  public void add(int number) {
    if (count[number] > 0)
      --freqCount[count[number]];
    ++count[number];
    ++freqCount[count[number]];
  }

  public void deleteOne(int number) {
    if (count[number] == 0)
      return;
    --freqCount[count[number]];
    --count[number];
    ++freqCount[count[number]];
  }

  public boolean hasFrequency(int frequency) {
    return freqCount[frequency] > 0;
  }

  private int[] freqCount = new int[100_001];
  private int[] count = new int[100_001];
}
