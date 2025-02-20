SELECT
  Follower.follower,
  COUNT(DISTINCT Followee.follower) AS num
FROM Follow AS Follower
INNER JOIN Follow AS Followee
  ON (Follower.follower = Followee.followee)
GROUP BY 1
ORDER BY 1;
