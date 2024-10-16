public class Solution {
  public List<String> splitWordsBySeparator(List<String> words, char separator) {
    return words.stream()
        .flatMap(word -> Arrays.stream(word.split("\\" + separator)))
        .filter(word -> !word.isEmpty())
        .collect(Collectors.toList());
  }
}
