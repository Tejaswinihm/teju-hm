# write a shell script to display the calender for the current month with current date replaced by * or ** 
depending whether the date is one digit or two digit



d=`date +%d`
d=`expr $d + 0`
l=`cal | tr -d "[\137][\010]" | grep -wn "$d" | head -c 1`
if [ $d -gt 9 ]
then
cal | tr -d "[\137][\010]" | sed "$1 s/$d/**/"
else
cal | tr -d "[\137][\010]" | sed "$1 s/$d/*/"
fi

