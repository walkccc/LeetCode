SELECT
  Users.user_id,
  Users.name,
  SUM(IFNULL(Rides.distance, 0)) AS 'traveled distance'
FROM Users
LEFT JOIN Rides
  USING (user_id)
GROUP BY 1
ORDER BY 1;
