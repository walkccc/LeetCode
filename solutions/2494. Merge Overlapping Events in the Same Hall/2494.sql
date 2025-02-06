WITH
  HallEventsWithIsNewEvent AS (
    SELECT
      hall_id,
      start_day,
      end_day,
      IFNULL(
        start_day > MAX(end_day) OVER(
          PARTITION BY hall_id
          ORDER BY start_day,
            end_day DESC ROWS BETWEEN UNBOUNDED PRECEDING AND 1 PRECEDING
        ),
        1
      ) AS is_new_event
    FROM HallEvents
  ),
  HallEventsWithGroupId AS (
    SELECT
      hall_id,
      start_day,
      end_day,
      SUM(is_new_event) OVER(
        PARTITION BY hall_id
        ORDER BY start_day, end_day DESC
      ) AS group_id
    FROM HallEventsWithIsNewEvent
  )
SELECT
  hall_id,
  MIN(start_day) AS start_day,
  MAX(end_day) AS end_day
FROM HallEventsWithGroupId
GROUP BY hall_id, group_id;
