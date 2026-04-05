SELECT
  IFNULL(
    ROUND(
      COUNT(DISTINCT session_id) / COUNT(DISTINCT user_id),
      2
    ),
    0.00
  ) AS average_sessions_per_user
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND  '2019-07-27';
