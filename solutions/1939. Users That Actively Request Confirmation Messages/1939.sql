WITH
  UserToTimestampDiff AS (
    SELECT user_id,
      TIMESTAMPDIFF(
        SECOND,
        time_stamp,
        LEAD(time_stamp) OVER(
          PARTITION BY user_id
          ORDER BY time_stamp
        )
      ) AS timestamp_diff
    FROM Confirmations
  )
SELECT DISTINCT user_id
FROM UserToTimestampDiff
WHERE timestamp_diff <= 24 * 60 * 60;
