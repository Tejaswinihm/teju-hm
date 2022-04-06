echo -n "enter the password"
stty -echo
read p1
echo "confirm the password"
stty echo
read p2 
while [ $p1 != $p2 ]
do
echo "password doesn't match reenter the password:"
stty -echo
read p3
stty echo
done
clear
echo "------------Terminal locked--------"
echo -n "enter the password to unlock"
stty -echo
read p3
stty echo
while [ $p1 != $p3 ]
do
echo "-----------Terminal locked--------"
echo -n "password doesn't match reenter the password"
stty -echo
read p3
stty echo
done
echo "---------Terminal unlock---------"

