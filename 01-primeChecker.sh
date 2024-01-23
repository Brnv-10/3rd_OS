# get a number from command line
number=$1

#prime function
is_prime(){
    if [ $1 -le 1 ]; then
      return 1
    fi 

    for((i = 2; i * i <= $1; i++)); do
       if [ $((number % i)) -eq 0 ]; then
       return 1
       fi 
    done

    return 0
}

# Check if the number is prime
is_prime $number

if [ $? -eq 0 ]; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi