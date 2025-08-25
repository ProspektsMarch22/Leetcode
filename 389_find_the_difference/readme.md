# 389. Find the Difference

### Programming Skills Study Plan

# Intuition

There are some aspects of this problem that facilitate a direct solution:

1. There is only ONE different element;
2. All elements are lowercase letters;

# Approach

Taking advantage that there is only lowercase letters, i create two arrays where i store information in the following way:

1. i represents the letter;
2. arr[i] represents the frequency of the letter in the respective given string;

So, this must be an int array, and i will create one for each given string. To wrap the program, i will compare the frequency of every lowercase letter in both strings. If i find that one single letter has a different frequency, i will return that letter.

# Conclusion

I think the skill that i'm building in this past challenges, since the N Queens one, is using single dimension arrays to represent more than one kind of information. 

I didn't necessarily use a string to represent an alphabet, i just took advantage that an alphabet is a ordered sequence of characters, so there is no way that the first letter of an alphabet is different than 'a', for example. 
