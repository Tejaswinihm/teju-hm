for i in $*
do
if [ -f $i ]
then
echo "------------$i contents are-----------"
cat $i | tr "[a-z]" "[A-Z]"
echo "-------"
else
echo "$file doesnt exists"
fi
done


