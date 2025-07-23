WITH
  TwoWayCalls AS (
    SELECT caller_id, recipient_id, call_time FROM Calls
    UNION ALL
    SELECT recipient_id, caller_id, call_time FROM Calls
  ),
  RankedCalls AS (
    SELECT
      caller_id,
      recipient_id,
      DATE(call_time) AS `date`,
      RANK() OVER(
        PARTITION BY caller_id, DATE(call_time)
        ORDER BY call_time ASC
      ) AS rank_asc,
      RANK() OVER(
        PARTITION BY caller_id, DATE(call_time)
        ORDER BY call_time DESC
      ) AS rank_desc
    FROM TwoWayCalls
  )
SELECT DISTINCT caller_id AS user_id
FROM RankedCalls
WHERE rank_asc = 1 OR rank_desc = 1
GROUP BY caller_id, `date`
HAVING COUNT(DISTINCT recipient_id) = 1;
