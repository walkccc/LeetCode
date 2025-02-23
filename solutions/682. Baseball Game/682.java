class Solution {
  public int calPoints(String[] operations) {
    Deque<Integer> scores = new ArrayDeque<>();

    for (final String operation : operations) {
      switch (operation) {
        case "+":
          final int lastScore = scores.pop();
          final int secondLastScore = scores.peek();
          scores.push(lastScore);
          scores.push(lastScore + secondLastScore);
          break;
        case "D":
          scores.push(scores.peek() * 2);
          break;
        case "C":
          scores.pop();
          break;
        default:
          scores.push(Integer.parseInt(operation));
      }
    }

    return scores.stream().mapToInt(Integer::intValue).sum();
  }
}
