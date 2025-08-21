# 2614. Prime In Diagonal

The actual challenge was to build a solid, quick and suscint "check if it is prime" function. The checking inside of the matrix is straight-foward, specially when the problem description leaves it clear which numbers i must check.

The principle behind the prime function lies in the definition that, after 3, a prime number falls into the formula:

`6k +- 1`

Which led me to check until the rounded-down square-root of the number inputed, with a iterator that was incremented 6 units per iteration.

The main function can be re-worked, since the while loop has redundant code.
