WITH
  RECURSIVE Calendar AS (
    SELECT 2 AS MONTH
    UNION ALL
    SELECT MONTH + 1
    FROM Calendar
    WHERE MONTH < 11
  )
SELECT
  Calendar.month - 1 AS MONTH,
  IFNULL(
    ROUND(
      (
        SELECT SUM(AcceptedRides.ride_distance)
        FROM Rides
        INNER JOIN AcceptedRides
          USING (ride_id)
        WHERE
          YEAR(Rides.requested_at) = '2020'
          AND MONTH(Rides.requested_at) IN (
            Calendar.month - 1,
            Calendar.month,
            Calendar.month + 1
          )
      ) / 3,
      2
    ),
    0
  ) AS average_ride_distance,
  IFNULL(
    ROUND(
      (
        SELECT SUM(AcceptedRides.ride_duration)
        FROM Rides
        INNER JOIN AcceptedRides
          USING (ride_id)
        WHERE
          YEAR(Rides.requested_at) = '2020'
          AND MONTH(Rides.requested_at) IN (
            Calendar.month - 1,
            Calendar.month,
            Calendar.month + 1
          )
      ) / 3,
      2
    ),
    0
  ) AS average_ride_duration
FROM Calendar;
