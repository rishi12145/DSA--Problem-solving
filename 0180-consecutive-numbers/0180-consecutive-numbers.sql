# Write your MySQL query statement below
select distinct t1.num as ConsecutiveNums
from Logs as t1
join Logs as t2
on t1.id = t2.id + 1
and t1.num = t2.num
join Logs as t3
on t2.id = t3.id + 1
and t2.num = t3.num;