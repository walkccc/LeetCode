public class AuthenticationManager {
  public AuthenticationManager(int timeToLive) {
    this.timeToLive = timeToLive;
  }

  public void generate(String tokenId, int currentTime) {
    tokenIdToExpiryTime.put(tokenId, currentTime);
    times.add(currentTime);
  }

  public void renew(String tokenId, int currentTime) {
    Integer expiryTime = tokenIdToExpiryTime.get(tokenId);
    if (expiryTime == null || currentTime >= expiryTime + timeToLive)
      return;
    times.remove(expiryTime);
    tokenIdToExpiryTime.put(tokenId, currentTime);
    times.add(currentTime);
  }

  public int countUnexpiredTokens(int currentTime) {
    final int expiryTimeThreshold = currentTime - timeToLive + 1;
    times.headSet(expiryTimeThreshold).clear();
    return times.size();
  }

  private final int timeToLive;
  private final Map<String, Integer> tokenIdToExpiryTime = new HashMap<>();
  private final TreeSet<Integer> times = new TreeSet<>();
}
