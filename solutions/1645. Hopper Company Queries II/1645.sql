WITH
  RECURSIVE Calendar AS (
    SELECT 1 AS month
    UNION ALL
    SELECT month + 1
    FROM Calendar
    WHERE month < 12
  )
SELECT
  Calendar.month,
  IFNULL(
    ROUND(
      (
        SELECT COUNT(DISTINCT AcceptedRides.driver_id)
        FROM AcceptedRides
        INNER JOIN Rides
          USING (ride_id)
        WHERE
          YEAR(Rides.requested_at) = '2020'
          AND MONTH(Rides.requested_at) = Calendar.month
      ) / (
        SELECT COUNT(*)
        FROM Drivers
        WHERE YEAR(Drivers.join_date) < '2020'
          OR (
            YEAR(Drivers.join_date) = '2020'
            AND MONTH(Drivers.join_date) <= Calendar.month)
      ) * 100,
      2
    ),
    0
  ) AS working_percentage
FROM Calendar;
