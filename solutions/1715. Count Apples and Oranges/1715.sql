SELECT
  SUM(Boxes.apple_count + IFNULL(Chests.apple_count, 0)) AS apple_count,
  SUM(Boxes.orange_count + IFNULL(Chests.orange_count, 0)) AS orange_count
FROM Boxes
LEFT JOIN Chests
  USING (chest_id);
