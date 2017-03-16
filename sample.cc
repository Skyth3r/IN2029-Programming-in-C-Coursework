#include <iostream>
#include <vector>
#include <string>
#include "sample.h"

using namespace std;

sample::sample(){}
// Converts vec1 into global var sally (vec1 --> v --> sally)
sample :: sample(vector <long double> v) : sally(v){}

// THIS IS THE MAIN
int main_test(int argc, char *argv[]) {
	/* an empty sample object - initialise with a vector once
	 * you have defined the sample constructor that takes a
	 * vector
	 */

   // Creating a vector called 'vec1'
 	vector<long double> vec1 {7, 11, 2, 13, 3, 5};

  // Creating a sample object
	// a_sample is the name of the object
  sample a_sample(vec1); // = { 7, 11, 2, 13, 3, 5};
	cout << "\tBefore city_test()\n";
	city_test(a_sample);
	cout << "\tAfter city_test()\n";


	/* Place your code for testing sample after this line. */
	
	//============ OLD CODE ==============
	// Creating a sample object
	// a_sample is the name of the object
	//sample a_sample(vec1);
	//====================================

	// To test each question, uncomment the code under each question,
	// save the file the make sample then run it.

	// Question 1 (Prining) and Question 2 (Overloading)
  // cout << a_sample << endl;

	// Question 3
  // All code in sample.h

	// Question 4 (Finding the minimun)
	//cout << a_sample.minmun() << endl;

	// Question 5 (Finding the maxium)
	//cout << a_sample.maxium() << endl;

	// Question 6 (Find the range)
	//cout << a_sample.range() << endl;

	// Question 7 (Finding the midrange)
	//cout << a_sample.midrange() << endl;

	// Question 8 (Finding the mean)
	//cout << a_sample.mean() << endl;

	// Question 9 (Finding the variance)
	//cout << a_sample.variance() << endl;

	// Question 10 (Finding the standard deviation)
	//cout << a_sample.std_deviation() <<endl;

	// Question 11 (Finding the median)
	//cout << a_sample.median() <<endl;

	// Question 12
  // This runs just the input for Q12
	//while (cin>>a_sample)
	//if (cin.bad()) cerr << "\nBad input\n\n";

  // This allows you to input the vector and then find the
  // minimum, range median, variance, maxium, midrange,
  // mean and standard deviation.
  while (cin  >> a_sample)
  cout  << a_sample   << endl
        << a_sample.minimum()   << endl
        << a_sample.range()     << endl
        << a_sample.median()    << endl
        << a_sample.variance()  << endl
        << a_sample.maximum()   << endl
        << a_sample.midrange()  << endl
        << a_sample.mean()      << endl
        << a_sample.std_deviation() << endl;
if (cin.bad()) cerr << "\nBad input\n\n";
return(0);

// Question 13
// In samplet.h

// Question 14
// Limits of long double restricted to 1.7E-308 to 1.7E+308
// Fixed by using long long as they can hold upto 64 bits

	return 0;
}
