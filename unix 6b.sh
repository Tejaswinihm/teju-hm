#write a shell script to list all the files in a directory whose filename is atleast 10 characters.


for i in `ls`
do
fl=`expr length $i`
if [ $fl -ge 10 ]
then
echo $i
fi
done

