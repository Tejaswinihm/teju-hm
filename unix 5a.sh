#write a shell script that accepts filename as argument and display its creation time if file exist and if doesnt send output
error message

 filename=$1
if [ -e $filename ]
then
set -- `ls -ld $filename`
echo "creation time of $filename is $6 $7 $8"
else
echo "file doesnt exit"
fi

