class Solution {
  public int finalPositionOfSnake(int n, List<String> commands) {
    Map<String, int[]> directions = Map.of("UP", new int[] {-1, 0},   //
                                           "RIGHT", new int[] {0, 1}, //
                                           "DOWN", new int[] {1, 0},  //
                                           "LEFT", new int[] {0, -1});
    int i = 0;
    int j = 0;

    for (final String command : commands) {
      int[] direction = directions.get(command);
      i += direction[0];
      j += direction[1];
    }

    return i * n + j;
  }
}
