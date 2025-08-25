# The "N Queens" Problem

## First Intuition

The problem of the N Queens imposes me with the task to check, multiple times, the same spots for valid position. This would be similar to a game of Skyscrappers or Sudoku. And quickly searching for algorithms that deal with this kind of problem, i found about "backtracking". 

Backtracking is a recursive algorithm that, in this case, will be used to:

1. If position checked was safe, put a queen in that position;
2. Move to the following column;
3. If there is no safe position in this column, go back to the last column and change the position of the queen in it.

Usually, the recursive algorithms that i dealt with so far involved an implementation of a base case, and a return with a modified argument calling the same function. A backtracking recursive algorithm does that, but inside a loop.

This lets me do exactly what i aim to in those steps: check until its safe, if its not safe, go back, and check again until its safe, go back...

## Implementing the check

Before implementing the backtracking function, i have to define a good way to:

1. Check for valid positions;
2. Store the positions smartly;

These things are interconnected. The way i represent my board will change the way i will check positions on it. So for that i choose the simplest way possible: a one dimensional int array.

If n = 4, then my board will be a simple:

`int board[4]`

The one dimensional representation works like this: the index represents the row, and the value represents the column in which the queen is. 

So an array that looks like this:

`{2, 4, 1, 3}`

Tells me that there is a queen on the 2nd row, 1st column, a queen in the 4th row, 2nd column, etc.

So, in a prototype like this:

`int    check_queen(int *board, int row, int col)`

I can perform vertical checks with this condition:

`if (board[i] == col)`

Why vertical checks? Because the checks are performed by looking at the rows individually. And since the array is onedimensional, i only have one possible value by index. In the backtracking section, there will be a drawing example.

But the diagonal checks, from both sides, can be done by this other condition, which is derived from a mathematical concept - the absolute value of the difference between the row and column positions must be different from the absolute value of the difference between the column and row checked. A mouthful, right? But it can be expressed with a condition like this:

`if (ft_abs(board[i] - col) == ft_abs(i - row)`

So, verifying these conditions tells me that i don't have a valid position. If a position checked fail these conditions, then i have a safe position.

OBS.: To not use the math library, i developed my own abs function, which i called ft_abs.

The full checking part of the code ends up like this:

```
int    ft_abs(int a)
{
    return ((a < 0) ? -a : a);
}

int check_queen(int *board, int row, int col)
{
    for(int i = 1; i < row; i++)
        if (board[i] == col || ft_abs(board[i] - col) == ft_abs(i - row))
            return (0);
    return (1);
}
```

## The Backtracking

In order to backtrack, as was presented in the intuition section, must be done recursively, inside an iteractive structure. And that will work like this:

1. I will examine a row.
2. I will check the row, by iterating through its columns, until i found a safe position.
3. If i find it, i will put a queen there, and if i am not at the last row, i will call the function again, with row + 1.
4. If the last instance of recursion don't find a safe position, it will end and come back to the layer of recursion immediately before it, and continue to iterate through the columns until it finds a safe position.

I will try drawing it for a n = 4 case.

First, i see the row #1. Since the board array has nothing in it, it will save a queen in the 1st row, 1st column:

<img width="138" height="124" alt="Screenshot_23-Aug_21-41-02_18057" src="https://github.com/user-attachments/assets/587de0ae-8ff0-4416-8f98-8d2ac7ecf506" />

Since it got a safe place, it will call the function to the next row. In terms of recursion, we are already looking to something like this:

```
solving_queen(row) //stoped at first column
    solving_queen(row + 1)
```

And we are looking to a board array like this: {1, *, *, *}

The * represents garbage.

While checking, it will see that board[i] == col, since the iteration starts with 1 to easy the implementation. So it will skip the first column of the 2nd row. The 2nd column of the 2nd row will also be skipped, since it falls for the absolute difference check. It will go the third column, and find a safe place.

 <img width="134" height="124" alt="Screenshot_23-Aug_21-43-44_12712" src="https://github.com/user-attachments/assets/a8d37683-e531-4c91-ad49-7f2f3b0d2f13" />

Next, we have:

```
solving_queen(row) //stoped at first column
    solving_queen(row + 1) //stoped at third column
        solving_queen(row + 2)
```

And we are looking to a board array like this: {1, 3, *, *}

At this point, we come to an interesting conclusion: we don't have safe spots. The first column has a queen, the 2nd and 4th columns are diagonally adjacent to the queen at the 2nd row, and the 3rd column is vertically aligned with this latter queen. So the program will iterate through all the columns, and none of the spots will check. So the function will finish its execution. And we will come back to the immediately back recursion call:

```
solving_queen(row) //stopped at first column
    solving_queen(row + 1) // will now resume from the third column
```

And there we have it!

The code for the backtracking function looks like this:

```
void   solve_queen(int row, int *board, int n, char ****solutions, int *count)
{
    for(int col = 1; col <= n; col++)
    {
        if (check_queen(board, row, col))
        {
            board[row] = col;
            if (row == n)
                save_solution(board, n, solutions, count);
            else
                solve_queen(row + 1, board, n, solutions, count);
        }
    }
}
```

## Saving the solution

Now for the worst part. I think you notice that ominous char ****solutions pointer in the last function call. Yes. Yikes. But we'll get to that.

The solution, as for the expected output from the leetcode challenge, must be an array of arrays, containing strings that represent the chess board with the placement of the queens marked by a 'Q', and the empty spots marked as '.'.

So, for a solution of n = 4, for example, it would be this:

`[[".Q..", "...Q", "Q...", "..Q."], [Other solution]]`

Since strings in C are also arrays, an array of arrays of strings, can be returned by a pointer to a pointer to a pointer to a char.

The first intuition is that of "i have to know how many solutions that is, so i can dynamically allocate memory for the outer array". And for that approach we would have to do the backtracking one time just for calculating the number of solutions, and other time to calculate the positions. That doesn't work well. 

So i must create a way to dynamically reallocate memory for the outer array. 

Inside of the solutions array, there are arrays of n + 1 size, that represent the chess boards. And inside of these arrays, there are strings (arrays) of n + 1 size that represent the rows of these boards. 

Using a reference passed count variable, and a reference passed solutions array (since its a memory address to a ***char pointer, it is a ****char - that's where IT comes from!).

In the main function, i can declare these "global" variables (count and solutions), and inside a "save_solution" function, i can:

1. Update "solutions" size everytime i find a solution
2. Fill the new spot with the array of strings, created with dynamic memory
3. Fill the array of strings with n placeholder strings like "...."
4. Change the dots for "Q"s according to the board array

The code for the save_solution function is this:

```
void   save_solution(int *board, int n, char ****solutions, int *count)
{
    *solutions = realloc(*solutions, sizeof(char **) * (*count + 1)); \\ This will update the size of solutions each time the save_solution is called, and it will be called everytime the backtracking function finds a solution.
    for (int i = 1; i <= n; i++)
    {
        (*solutions)[*count][i - 1] = malloc(n + 1); //Creates the string inside the array inside the array of arrays;
        memset((*solutions)[*count][i - 1], '.', n); //Fill the array with '.'
        (*solutions)[*count][i - 1][board[i] - 1] = 'Q'; //With the column in which the queen is saved, i can directly change the column of the solution array to Q respectively
        (*solutions)[*count][i - 1][n] = '\0';
    }
    *count += 1;
}
```

## The solveNQueens Function

With all parts set and working, the principal function looks like this:

```
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
    int board[n + 1];
    char ***solutions;
    int count;

    count = 0;
    solutions = NULL;
    solve_queen(1, board, n, &solutions, &count);
    *returnSize = count;
    *returnColumnSizes = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
        (*returnColumnSizes)[i] = n;
    return (solutions);
}
```

The returnSize and returnColumnSizes variable serves nothing to the output, and are merely an obligation set by the challenge.

## Conclusion

This challenge was a great lesson in the concepts of backtracking and dealing with functions such as memset and realloc.
It gave me a solid idea about how to apply recursion not only as a means to implement a solution, but to implement an algorithm suited to
a particular class of problems. The same algorithm could be used, for instance, in a "Solve Sudoku" or "Solve Skyscrappers" program - or any
situation where the job is analyze placement of elements within static position restraints.

A very similar problem to which we could apply this kind of solution is to calculate safe positions in a checkers game - of course, by changing the "check_queen" conditions we could extend this sort of solution to any particular, singular, chess piece. The thing with checkers is that all of the game's pieces have the same range of movement, so it would be a very close implementation to this one.
