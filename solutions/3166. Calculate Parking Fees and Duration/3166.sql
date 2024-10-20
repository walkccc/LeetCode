WITH
  Cars AS (
    SELECT
      car_id,
      SUM(fee_paid) AS total_fee_paid,
      SUM(TIMESTAMPDIFF(MINUTE, entry_time, exit_time)) AS total_duration
    FROM ParkingTransactions
    GROUP BY 1
  ),
  CarToDurationPerLot AS (
    SELECT
      car_id,
      lot_id,
      SUM(TIMESTAMPDIFF(MINUTE, entry_time, exit_time)) AS duration_per_lot
    FROM ParkingTransactions
    GROUP BY 1, 2
  ),
  CarToMaxDurationPerLot AS (
    SELECT
      car_id,
      MAX(duration_per_lot) AS max_duration_per_lot
    FROM CarToDurationPerLot
    GROUP BY 1
  )
SELECT
  Cars.car_id,
  Cars.total_fee_paid,
  ROUND(Cars.total_fee_paid * 60 / Cars.total_duration, 2) AS avg_hourly_fee,
  CarToDurationPerLot.lot_id AS most_time_lot
FROM Cars
INNER JOIN CarToDurationPerLot
  USING (car_id)
INNER JOIN CarToMaxDurationPerLot
  USING (car_id)
WHERE
  CarToDurationPerLot.duration_per_lot = CarToMaxDurationPerLot.max_duration_per_lot
ORDER BY 1;
