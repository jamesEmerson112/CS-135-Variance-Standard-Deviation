//***************************************************************************************
// An Vo Lec 1003 Lab 1006 Assginment 04
// 
// This C++ program will interactively prompt the user for the name of the input file and
// read it, open the file for reading, using a C++ filestream, read the interger values
// from the file. It will count and sum the negative values, compute the average if
// possiple, store the other values (>=0) in an array, counting them as they are read.
// After that, the program will interactively prompt the user for the name of the output
// file and read it, open the file for writing using a C++ filestream, write te following
// to the output file the author created - leave at least one blank line between each set 
// of outputs and clearly label all output.
//
// Input: 	A data file contains a series of integer values(positive, negative, and zero).
//			The maximum number of values in the file that are greater than or equal to
//			0 will be 30. Please note, there may be more than 30 numbers in the file.
//			Each value will be separated by at least one blank space and the last value
//			in the file will be followed by a line feed
//
// Output:	A data file contains:
//				The author's name, lecture section #, assignment #
//				If there were no negative values in the file, display an appropriate 
//				message
//				If there were negative values in the file display
//					the sum and count of the negative values
//					the average of the negative values
//				If there were values >= 0 stored in the array
//					use bubblesort to arrange the values in the array into ascending
//					order
//					list the values sorted values one per line, right justified, values
//					may have up to 7 digits
//					display the number of values stored in the array, the average of the
//					values, the variance and the standard deviation of the values
//					list all the values in the array that are prim or an appropriate 
//					message if there are none
//					list each nonprime numbers greater than 0 found in the array along
//					with how many factors each has or an appropriate message if there
//					are none
//				Otherwise, display an appropriate message
//***************************************************************************************

	// Header file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

	// Function prototypes
void bubblesort(int[], int);			// function to sort numbers
void printNegativeOutput(ofstream&, 
						 int, int);		// function to display the sum and 
										// count of the negative values
										// the average of the negative values
void printPositiveNumber(ofstream&,
						int[], int);	// function to print positive numbers
void printPrimeNumber(ofstream&,
					  int[], int);		// function to print prime numbers
double average(int, int);				// variable to find the average of given data
double variance(int[], double, int);	// variable to find the variance of given data
double standardVariance(double);		// variable to find the standard variance of given data

int main()
{
		// Declare variables
	ifstream in;								//input stream variable for data files
	ofstream out;								//output stream variable
	string inDataName;							//input data name
	string outDataName;							//output data name
	int negativeCount = 0;						//variable to count the negative values 
	int positiveCount = 0;						//variable to count the positive values
	int numbers;								//variable to hold inputs
	int sumNegative = 0;						//sum for negative values
	int positiveNumbers[30];	//array for positive values
	int sumPositive = 0;						//sum for positive values

		// 	• interactively	prompt the user for	the	name of	the	input file and read it
	cout << "Please enter the name of the input file:"
		 << endl;
	cin >> inDataName;

		//	• open the file	for	reading, using a C++ filestream
	in.open(inDataName.c_str());

		//	• read the integer values from the file
	if (!in) 
	{//1st if
		cout << "file not opened for input" << endl;
	}//1st close
	else
	{//1st else
			// take inputs	
		in >> numbers;		
		while (in)
		{//2nd while
			if(numbers > 10000000 || numbers < -10000000)
			{
				out << "Values need to have 7 digits or less"
					<< endl;
				break;
			}
			if(numbers < 0)
			{//3rd if 	
				//	◦ count	and	sum	the	negative values, compute the average if	possible
				sumNegative = sumNegative + numbers;								
				negativeCount++;
			}//3rd E if
			if(numbers >= 0)
			{//3rd if
				//	◦ store	the	other values (>=0) in an array,	counting them as they are read
				positiveNumbers[positiveCount] = numbers;
				sumPositive = sumPositive + positiveNumbers[positiveCount];
				positiveCount++;
		 	}//3rd E if
			in >> numbers;
		}//2nd E while
		
		//	• interactively	prompt the user	for	the	name of	the	output file	and	read it
		cout << "Please enter the name of the output file:"
			 << endl;
		cin >> outDataName;

		//	• open the file	for	writing	using a	C++	filestream
		out.open(outDataName.c_str());

		//	• write	the	following to the output	file you created - leave at	least one blank	line between	
		//	each set of	outputs	and	clearly	label all output
		// 	◦ your	name,	lecture	section	#,	assignment	#
		out << "An Vo \t lecture section 1003 \t  Assignment 04" 
			<< endl
			<< endl;
		
		// 	◦ if there were no negative values from the file, display an appropriate message
		if (negativeCount == 0)
		{//2nd if
			out << "There are no negative values from the file " 
				<< "\""
				<< inDataName
				<< "\""
				<< endl
				<< endl;
		}//2nd close
		
		//	• the sum and count	of the negative	values
		//	• the average of the negative values
		else
		{//2nd else
			printNegativeOutput(out, sumNegative, negativeCount);
		}//2nd close
		
		//	◦ if there were no values >= 0 in the file, display an appropriate message
		if (positiveCount == 0)
		{//2nd if
			out << "There are no positive values from the file " 
				<< "\""
				<< inDataName
				<< "\""
				<< endl
				<< endl;
		}//2nd close
		else
		{//2nd if	
		// ◦ if	there are values >=	0 stored in	the	array	
		// • use  bubblesort (refer  to  the  bubblesort handout) to  arrange the values in	
		// the array into ascending	order			
			bubblesort(positiveNumbers, positiveCount);
			out << "Numbers >= 0 Data"
				<< endl;
			out << setw(17) << setfill('=') << "="
				<< endl;
			out << "Positive #'s in File"
				<< endl;

		//	• list the values sorted values one per line, right justified, values may have up	
		//  to 7 digits	
		//	• display the number of	values stored in the array,	the	average	of the values,	
		//	the variance and the standard deviation of the values (set precision to 5
		//	decimal	places)	
			printPositiveNumber(out, positiveNumbers, positiveCount);
	
			out << endl;
			out << fixed << showpoint;
			out << setprecision(5);
			out << "Average: " 
				<< average(sumPositive, positiveCount)
				<< endl;
			out << "Variance: " 
				<< variance(positiveNumbers, average(sumPositive, positiveCount), positiveCount)
				<< endl;
			out << "Standard deviation: " 
				<< standardVariance(variance(positiveNumbers, average(sumPositive, positiveCount), positiveCount))
				<< endl
				<< endl;

		// • list all the values in	the	array that are prime (one per line,	right justified) or	
		// an appropriate message if there are none
		//	• list each nonprime numbers greater than 0 found in the array along with	
		//	how many gactors each has (arrange in the 2 columns - right justified) or an	
		//	appropriate	message	if there are none	
			printPrimeNumber(out, positiveNumbers, positiveCount);
			out << endl;
		}//2nd close
	}//1st close
	in.close();
	out.close();

	return 0;
}
//************************************************************************************
void printPrimeNumber(ofstream& output,
					  int data[], int n)	
// Given the file stream to print output (output),
// the given array (data[]), and the size of the array (n),
// printPrimeNumber will determine whether the data array has
// prime numbers. If there are prime numbers, printPrimeNumber will
// print them. If there are none of prime numbers, printPrimeNumber
// will display an appropriate message. Furthermore, printPrimeNumber
// also prints nonprime numbers and their factors if there are any
// nonprime numbers. Otherwise, printPrimeNumber will display
// an appropriate message
{
	int nonPrimeCount = 0;			//variable to count the number of nonprime numbers
	int primeCount = 0;				//variable to count the number of prime numbers
	int primeNumbers[n];			//array to hold prime numbers
	int nonPrimeNumbers[n];			//array to hold nonprime numbers
	int factors[n];					//array to hold numbers of factors
	int orderNonPrimeNumber = 0;	//variable to hold the order of nonprime number
	int factorsCount = 0;			//variable to count if there are any factors from non
									//prime numbers
	for (int i = 0 ; i < n; i++)
	{
		if (data[i] > 1)
		{for (int j = 2; j < data[i]; j++)
				{
					if(data[i] % j == 0)
					{
						factorsCount++;
					}
				}
		
				if (factorsCount == 0)
				{
					primeNumbers[primeCount] = data[i];
					primeCount++;
				}
				else if(factorsCount != 0)
				{
					nonPrimeNumbers[nonPrimeCount] = data[i];
					factors[orderNonPrimeNumber] = factorsCount + 2;	
					orderNonPrimeNumber++;
					nonPrimeCount++;
				}
		
				factorsCount = 0;}
	}

	if (primeCount == 0)
	{
		output << "There are no prime numbers in the file" 
			   << endl
			   << endl; 
	}
	else if (primeCount != 0)
	{
		output << "Prime Numbers" << endl;
		for (int a = 0; a < primeCount; a++)
		{
			output << setw(10) << primeNumbers[a] << endl;
		}
		output << endl;
	}

	if (nonPrimeCount ==0)
	{
		output << "There are no nonprime numbers in the file"
			   << endl;
	}
	else if (nonPrimeCount != 0)
	{
		output << "Nonprime Numbers and Factor Counts"
			   << endl;
		for (int b = 0; b < nonPrimeCount; b++)
		{
			output << setw(10) << nonPrimeNumbers[b]
				   << setw(10) << factors[b]
				   << endl;
		}
	} 
}

//***********************************************************************************
void printNegativeOutput(ofstream& output,
						 int sum, int n)
// Given the output location file (output), the given sum 
// (data[]) and the count of negative numbers (n),
// printPositiveNumber will display the count of negative
// numbers, the count of negative numbers, the sum of negative numbers
// and the average of negative numbers
{
	output << "Negative Number Data" 
		   << endl;
	output << setw(20) 
		   << setfill('=') << "=" 
		   << endl;

	output << "Count: " 
		   << n 
		   << endl;
	output << "Sum: " 
		   << sum << endl;

	output << "Average: " 
		   << average(sum, n)
		   << endl << endl;
}

//***********************************************************************************
void printPositiveNumber(ofstream& output,
						int data[], int n)
// Given the output location file (output), the number array 
// (data[]) and the size of the array (n),
// printPositiveNumber will display the positive number
{
	for (int i = 0; i < n; i++)
	{
		output << right
			   << setw(10) << setfill(' ')
			   << data[i]
			   << endl;
	}	
}

//************************************************************************************
void bubblesort(int data[ ],int count)
// Sort an array of integers into ascending order.
// Parameters: data[]
// data: array of floategers to be sorted
// count: (int) number of values in the array
// Value passed back: sorted data
{
	 int temp; //place holder when values are interchanged
	 for (int i=0; i < count-1; i++)
		 for (int j=0; j < count-(i+1); j++)
			 if (data[j] > data[j+1])
			 {
				 temp = data[j];
				 data[j] = data[j+1];
				 data[j+1] = temp;
			 }
}

//************************************************************************************
double average(int sum, int n)
// Given the sum (sum) and the number of values,
// the function average will compute and return
// the average number
{
	double result;			//variable to hold the average
	result = static_cast<double> (sum) / n;
	return result;
}

double variance(int data[], double ave, int n)
// Given the number array (data[]), the average (ave),
// the size of the array (n), the function variance will compute
// and return the variance of the number array
{
	double addition = 0;
	double result;			//variable to hold the variance
	for (int i = 0; i < n; i++)
	{
		addition = addition + pow((data[i] - ave), 2);
	}
	result = addition / (n-1);
	return result;
}

double standardVariance(double variance)
// Given the variance (variance), the function
// standardVariance will compute and return
// the standard variance when given a variance
{
	double result;			//variable to hold the standard variance
	result = sqrt(variance);
	return result;
}
//************************************************************************************