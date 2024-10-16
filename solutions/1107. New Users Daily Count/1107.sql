WITH
  UserToLoginDate AS (
    SELECT
      user_id,
      MIN(activity_date) AS login_date
    FROM Traffic
    WHERE activity = 'login'
    GROUP BY 1
  )
SELECT
  login_date,
  COUNT(*) AS user_count
FROM UserToLoginDate
WHERE DATEDIFF('2019-06-30', login_date) <= 90
GROUP BY 1;
