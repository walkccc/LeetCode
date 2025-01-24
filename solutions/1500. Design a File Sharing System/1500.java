class FileSharing {
  public FileSharing(int m) {
  }

  public int join(List<Integer> ownedChunks) {
    final int userId =
        availableUserIds.isEmpty() ? userToChunks.size() + 1 : availableUserIds.poll();
    userToChunks.put(userId, new HashSet<>(ownedChunks));
    for (final int chunk : ownedChunks) {
      chunkToUsers.putIfAbsent(chunk, new TreeSet<>());
      chunkToUsers.get(chunk).add(userId);
    }
    return userId;
  }

  public void leave(int userID) {
    for (final int chunk : userToChunks.get(userID)) {
      chunkToUsers.get(chunk).remove(userID);
      if (chunkToUsers.get(chunk).isEmpty())
        chunkToUsers.remove(chunk);
    }
    userToChunks.remove(userID);
    availableUserIds.offer(userID);
  }

  public List<Integer> request(int userID, int chunkID) {
    if (!chunkToUsers.containsKey(chunkID))
      return new ArrayList<>();
    List<Integer> userIds = new ArrayList<>(chunkToUsers.get(chunkID));
    userToChunks.get(userID).add(chunkID);
    chunkToUsers.get(chunkID).add(userID);
    return userIds;
  }

  private Map<Integer, Set<Integer>> userToChunks = new HashMap<>();
  private Map<Integer, Set<Integer>> chunkToUsers = new HashMap<>();
  private Queue<Integer> availableUserIds = new PriorityQueue<>();
}
