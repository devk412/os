echo enter the string
read a
sum=0
temp=$a
while [ $a -gt 0 ]
do
	r=$((a%10))
	sum=$((((sum*10))+r))
	a=$((a/10))
done
if [ $temp -eq $sum ]
then
	echo it is a palindrome
else
	echo not a palindrome
fi
