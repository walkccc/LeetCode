WITH
  FreeSeats AS (
    SELECT
      *,
      seat_id - ROW_NUMBER() OVER(ORDER BY seat_id) AS group_id
    FROM Cinema
    WHERE free = 1
  ),
  RankedFreeSeats AS (
    SELECT
      MIN(seat_id) AS first_seat_id,
      MAX(seat_id) AS last_seat_id,
      COUNT(*) AS consecutive_seats_len,
      RANK() OVER(ORDER BY COUNT(*) DESC) AS `rank`
    FROM FreeSeats
    GROUP BY group_id
  )
SELECT first_seat_id, last_seat_id, consecutive_seats_len
FROM RankedFreeSeats
WHERE `rank` = 1
ORDER BY 1;
