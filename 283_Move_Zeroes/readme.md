# 283. Move Zeroes
### Programming Skills Study Plan

## Intuition
When i thought about moving things in-place, i tried to take a strategy similar to a sorting program - not that i would compare a number in terms of magnitude, but just to check if it's zero. If it were, then i try to move it to the end.

The thing was that for some cases like [0, 0] or [0,0,1] that won't cut straight. 

## Final Strategy
The code then had to take a turn: this time, i acted as if i wanted to create a second array to return. So i fill this auxiliary array with zeros, and then append to it the numbers different from zero in their order of appearence. Then i copied the contents of this array to the original.

## Things to improve
The three loops bother me to some level. I tried implementing the copy part with memcpy, but i didn't get it right - and at the end, that would be another loop whatsoever. Maybe there is indeed a direct strat without the use of a buffer array.
