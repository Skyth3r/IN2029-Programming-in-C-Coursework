#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#include "city.hh"

class sample : public city {
  // DON'T CHANGE ANYTHING ABOVE THIS LINE!!! (You can add more includes)

  // Creating a global vector called sally
  vector<long double> sally;

  // Set to public so can be used by other files
  public:

  // Creates a constructor - default
  sample();

  // Creates a constructor that can take an input of a vector
  sample(vector <long double> v);

  // Question 1
  ostream& print(ostream &s){
    s << "<" << sally.size() << ": ";
    // Loop for displaying elements in vector
    for (unsigned int i=0; i < sally.size(); i++){
      s << sally[i] << " ";
    }
    s << ">" << endl;
    return s;
  }

  // ----- OLD CODE -----
  //void print() {
	    // Displaying vector in the format
	  //  cout << "<" << sally.size() << ": ";
      // Loop for displaying elements in vector
	    //for (unsigned int i=0; i < sally.size(); i++){
		    //  cout << sally[i] << " ";
	        //}
	    // cout << ">" << endl;
  //}

  // Question 2
  // Outside class

  // ----- OLD CODE -----
  // Overloading print with ariable vector
  //void print(vector<long double> sally2) {
	    // Displaying vector in the format
	  //  cout << "<" << sally2.size() << ": ";
      // Loop for displaying elements in vector
	    //for (int i=0; i < sally2.size(); i++){
		    //  cout << sally2[i] << " ";
	        //}
	     //cout << ">" << endl;
  //}

  // Question 3
  // Gets and retuns sally
  vector <long double> get_data(){
    return sally;
  }


  // Question 4
  // Finding the minimum
  long double minimum() {
    long double min1 = sally[0];
    for (unsigned int i = 0; i < sally.size(); i++){
        if (min1 > sally[i]){
          min1 = sally[i];
          }
        }
    return min1;
  }

  // Question 5
  // Finding the maximum
  long double maximum() {
    long double max1 = sally[0];
    for (unsigned int i = 0; i < sally.size(); i++){
        if (max1 < sally[i]){
          max1 = sally[i];
          }
        }
    return max1;
  }

  // Quesion 6
  // Finding the range
  long double range() {
    long double range1;
    // Finding the max using the max method
    long double max1 = this->maximum();
    // Finding the min using the min method
    long double min1 = this->minimum();

    // Calculating range
    range1 = max1 - min1;
    return range1;
  }

  // Question 7
  // Finding the midrange
  long double midrange() {
    long double midrange1;
    // Finding the max
    long double max1 = this->maximum();
    // Fidning the min
    long double min1 = this->minimum();
    // Calculating midrange
    midrange1 = (max1 - min1)/2;
    return midrange1;
  }

  // Question 8
  // Finding the mean
  long double mean() {
    // Starts with first element in vector
    long double mean1 = sally[0];
    // Calculating mean
    // i starts at 1 to prevent counting element[0] twice
    for (unsigned int i = 1; i < sally.size(); i++){
        mean1 = mean1 + sally[i];
      }
    mean1 = mean1/sally.size();
    return mean1;
  }

  // Question 9
  // Finding the variance
  long double variance() {
    // Getting the mean
    long double mean1 = this->mean();
    // Setting up var 1
    long double var1 = (sally[0] - mean1);
    // Sets first element for formula
    var1 = var1 * var1;
    // Adding each eleement after minus
    for (unsigned int i = 1; i < sally.size(); i++){
        var1 = var1 + (sally[i] - mean1)*(sally[i] - mean1);
      }
    var1 = var1 / sally.size();
    return var1;
  }

  // Question 10
  // Finding the standart deviation
  long double std_deviation() {
    long double dev1 = this->variance();
    // sqrt from #include <math.h>
    dev1 = sqrt(dev1);
    return dev1;
  }

  // Question 11
  // Finding the median
  long double median() {
    long double median1;
    // Sorts the elements in the vector sally
    // sort comes from #include <algorithm>
    sort(sally.begin(), sally.end());

    // Checking if vector is sorted
    // RESULT: vector is sorted
    //cout << "<" << sally.size() << ": ";
    // Loop for displaying elements in vector
    //for (unsigned int i=0; i < sally.size(); i++){
        //cout << sally[i] << " ";
        //}
     //cout << ">" << endl;

     // Checking if vector has an odd or even number of elements
     int y = sally.size(); // size = 4
     // Element counter
     double long i;

     // If sally.size is even - WORKING
     if (y % 2 == 0){
       // This just works - DONT CHANGE
       i = sally[0] + sally[y-1];
       median1 = i / 2;
       return median1;
     }
     //IF sally.size is odd - WORKING
        else {
          i = sally.size() / 2;
          median1 = sally[i];
          return median1;
     }
  }

  // Question 12
  // Outside class


};

// Question 2
ostream &operator<<(ostream &o, sample &s){
  return s.print(o);
}

// Question 12
istream & operator>>(istream &in, sample &a_sample){
  char larrow;
  char colon;
  char rarrow;
  int size;
  vector <long double> new_vec;

  if (in>> larrow){
  	if(larrow == '<'){
      if (in>>size){
				if (in >> colon && colon == ':'){
	  			for(unsigned int i = 0; i!=size; i++){
	    			long double input;
	    			in >> input;
	    			new_vec.push_back(input);
	  			}
	  			if(in >> rarrow && rarrow == '>'){
	    			a_sample = sample(new_vec);
					}else (cout << "\nInvalid Input, try again.\n")<< endl;
				}
      }
    }
  }
  return in;
}


/* With normal (non-generic) code, the source (.cc) includes the header (.h). */
#endif
