WITH
  FreeTrial AS (
    SELECT user_id, AVG(activity_duration) AS avg_free_trial_duration
    FROM UserActivity
    WHERE activity_type = 'free_trial'
    GROUP BY 1
  ),
  Paid AS (
    SELECT user_id, AVG(activity_duration) AS avg_paid_duration
    FROM UserActivity
    WHERE activity_type = 'paid'
    GROUP BY 1
  ),
  ConvertedUsers AS (
    SELECT DISTINCT FreeTrial.user_id
    FROM FreeTrial
    INNER JOIN Paid
      USING (user_id)
  )
SELECT
  ConvertedUsers.user_id,
  ROUND(FreeTrial.avg_free_trial_duration, 2) AS trial_avg_duration,
  ROUND(Paid.avg_paid_duration, 2) AS paid_avg_duration
FROM ConvertedUsers
INNER JOIN FreeTrial
  USING (user_id)
INNER JOIN Paid
  USING (user_id)
ORDER BY 1;
