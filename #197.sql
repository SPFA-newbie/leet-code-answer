# Write your MySQL query statement below

select id

    from Weather w 

    where w.Temperature > 

        (select Temperature 

            from Weather ww 

            where ADDDATE(ww.recordDate, 1) = w.recordDate)