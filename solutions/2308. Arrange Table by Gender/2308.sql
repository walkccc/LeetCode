SELECT
  user_id,
  gender
FROM Genders
ORDER BY RANK() OVER(
    PARTITION by gender
    ORDER BY user_id
  ),
  LENGTH(gender) DESC;
