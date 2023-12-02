SELECT
  contest_id,
  ROUND(
    COUNT(user_id) * 100 / (
      SELECT COUNT(*)
      FROM Users
    ),
    2
  ) AS percentage
FROM Register
GROUP BY 1
ORDER BY percentage DESC, contest_id;
