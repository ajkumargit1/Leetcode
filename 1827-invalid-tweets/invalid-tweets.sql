# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets AS t
WHERE LENGTH(t.content)>15