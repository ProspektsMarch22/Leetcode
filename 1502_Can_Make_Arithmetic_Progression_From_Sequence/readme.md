# 1502. Can Make Arithmetic Progression From Sequence

### Programming Skills Study Plan

## Intuition
I got this on the first try - following the intuition i've reached my final strategy.

First, i looked upon the constraints:

1. The minimum array size is 2;
2. The elements don't go over or under the limits of int;

So, there's the exceptional case where i have a sequence of 2 elements, which, in this context, will always be an arithmetic progression; and i don't have to create exceptions or a particular flow to deal with overflows/underflows.

Second, i had to sort the array in ascending format. It could be descendent, it really doesn't matter, as long as i can analyze the elements under the hypothesis that, under one of this formats, they represent an arithmetic progression. 

The `sort_array()` does precisely that. Rearrange the elements inside the array so they can be analyzed in ascending order. 

Third, after calling the `sort_array()` function in the main function, i took the difference between the first 2 elements and stored it in a variable called "ratio". 

Starting from the 2nd element onwards, until i reached the one before the last, i would check the difference between element at index `i` and element at index `i + 1`.

If the difference doesn't correspond to the value at `ratio`, then it's not an AP.

## Things to improve
Alternatively, i could add the ratio to element at index `i` and check if the value is equal to the value of the element at index ` i + 1`. It's pretty much the same in terms of complexity.

But i could do something really different:

I could check the start and end points of the array, after getting the ratio information. At the start, i would do the add check, and at the same time, i would check from the end point with another add check, but with `-ratio`. 

Doing two tests per iteration could speed things up, in the case the "culprit element" were close to one of these points - start or end. If it sits in the middle, i think my original approach would be best. The number of iterations would be the same, but the number of checks would be half.
