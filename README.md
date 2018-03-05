An Vo Lec 1003 Lab 1006 Assginment 04

This C++ program will interactively prompt the user for the name of the input file and
read it, open the file for reading, using a C++ filestream, read the interger values
from the file. It will count and sum the negative values, compute the average if
possiple, store the other values (>=0) in an array, counting them as they are read.
After that, the program will interactively prompt the user for the name of the output
file and read it, open the file for writing using a C++ filestream, write te following
to the output file the author created - leave at least one blank line between each set 
of outputs and clearly label all output.
```
Input: 	A data file contains a series of integer values(positive, negative, and zero).
- The maximum number of values in the file that are greater than or equal to 0 will be 30. Please note, there may be more than 30 numbers in the file.
- Each value will be separated by at least one blank space and the last value in the file will be followed by a line feed

Output:	A data file contains:
+ The author's name, lecture section #, assignment #
+ If there were no negative values in the file, display an appropriate message
+ If there were negative values in the file display	the sum and count of the negative values the average of the negative values
+ If there were values >= 0 stored in the array	use bubblesort to arrange the values in the array into ascending order
+ list the values sorted values one per line, right justified, values may have up to 7 digits
+ display the number of values stored in the array, the average of the values, the variance and the standard deviation of the values
+ list all the values in the array that are prim or an appropriate message if there are none
+ list each nonprime numbers greater than 0 found in the array along with how many factors each has or an appropriate message if there are none
+ Otherwise, display an appropriate message
```