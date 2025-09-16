# 896. Monotonic Array
### Programming Skills Study Plan

## Intuition
I went straightfoward comparing an element with the next,
keeping in mind that i have to solve for the case that the array has:

1. Only one element;
2. All equal elements;

Because these cases are too examples of a monotonic succession.

Therefore, i nailed a correct answer in terms of logic, but made some
mistakes regarding the syntax for the compiler.

The compiler can get somewhat confused if you use cascading if statements followed
by else statements. If there is only ifs that's ok, but in the case of else's, the
compiler simply don't know how to match the if-else pairs. So i've got some bad
submissions on account of that.

## Things to improve
This could be improved by use of the Two Pointers Technique.
I can reduce it to only one while, possibly, with quicker results in case of
late falses. This could severely improve the quality of this program, in everyway.

Knowing that, i will leave the program as-is for the moment, because it's 3:30 AM already
