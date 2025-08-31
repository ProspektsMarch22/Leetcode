# 66. Plus One

### Programming Skills Study Plan

## Intuition
Considering that addition implies carrying, my first thought was to convert the digits inside the given array into an integer, operate the sum, and then check how long was this number. With its length, i'd allocate the adequate space and then, i would decompose this integer and place its digits inside the malloced array.

This worked pretty well until i face arrays with lengths greater or equal to 19. There is no single data type capable of holding such a big number together in C. Therefore, the whole thingof dealing with a integer blown up.

## Final Strategy
I first thought about carrying, right? That's it: i should try to implement the addition algorithm, as we learn it in elementary school - you perform an addition by each digit, starting from the less significant one. If the sum is greater than 9, the modulo of the sum is put "below", and it carries 1 to the digit immediately to the left. If there is a carry from the first digit, then i will add 1 as the most significant digit, incrementing the length of the number in one more digit.

Since i'm adding only one, i could start the program with carry already set to one. And to deal with the length + 1 scenario, i will malloc an array with digitsSize + 1.

If by the last digit i have a carry, that means that my first digit is a 1. Else, and dealing with the case that the returned array length is equal to the length of the array passed as argument, and i'll have to malloc another array accordingly. After that, i will copy every digit from the bigger array to this smaller one. 

## Things to improve
I think there may be a way to malloc only one array. Maybe realloc could be useful in this case?
