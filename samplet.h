#ifndef _samplet_H_
#define _samplet_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#include "cityt.hh"

template <typename T>
class samplet : public cityt<T> {
  // DON'T CHANGE ANYTHING ABOVE THIS LINE!!! (You can add more includes)
private:
  vector<T> v ={};

public:
  samplet(){}
  samplet(vector<T> vec1) : v(sally){}
  //samplet(vector<T> vec1){}

  vector<long double> sally;

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

  // Question 2
  // Outside the class

  // Question 3
  // Gets and retuns sally
  vector <T> get_data(){
    return sally;
  }


  // Question 4
  // Finding the minimum
  T minimum() {
    T min1 = sally[0];
    for (int i = 0; i < sally.size(); i++){
        if (min1 > sally[i]){
          min1 = sally[i];
          }
        }
    return min1;
  }

  // Question 5
  // Finding the maximum
  T maximum() {
    T max1 = sally[0];
    for (int i = 0; i < sally.size(); i++){
        if (max1 < sally[i]){
          max1 = sally[i];
          }
        }
    return max1;
  }

  // Quesion 6
  // Finding the range
  T range() {
    T range1;
    // Finding the max using the max method
    T max1 = this->maximum();
    // Finding the min using the min method
    T min1 = this->minimum();

    // Calculating range
    range1 = max1 - min1;
    return range1;
  }

  // Question 7
  // Finding the midrange
  T midrange() {
    T midrange1;
    // Finding the max
    T max1 = this->maximum();
    // Fidning the min
    T min1 = this->minimum();
    // Calculating midrange
    midrange1 = (max1 - min1)/2;
    return midrange1;
  }

  // Question 8
  // Finding the mean
  T mean() {
    // Starts with first element in vector
    T mean1 = sally[0];
    // Calculating mean
    // i starts at 1 to prevent counting element[0] twice
    for (int i = 1; i < sally.size(); i++){
        mean1 = mean1 + sally[i];
      }
    mean1 = mean1/sally.size();
    return mean1;
  }

  // Question 9
  // Finding the variance
  T variance() {
    // Getting the mean
    T mean1 = this->mean();
    // Setting up var 1
    T var1 = (sally[0] - mean1);
    // Sets first element for formula
    var1 = var1 * var1;
    // Adding each eleement after minus
    for (int i = 1; i < sally.size(); i++){
        var1 = var1 + (sally[i] - mean1)*(sally[i] - mean1);
      }
    var1 = var1 / sally.size();
    return var1;
  }

  // Question 10
  // Finding the standart deviation
  T std_deviation() {
    T dev1 = this->variance();
    // sqrt from #include <math.h>
    dev1 = sqrt(dev1);
    return dev1;
  }

  // Question 11
  // Finding the median
  T median() {
    T median1;
    // Sorts the elements in the vector sally
    // sort comes from #include <algorithm>
    sort(sally.begin(), sally.end());

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
  // Outside the class



};

// ALL OPS OUTSIDE CLASS (IN/OUT ONES)

template <typename T>
// Question 2
// Might have to move outside the class
ostream& operator<<(ostream &o, samplet<T> &s){
  return s.print(o);
}

template <typename T>
// Question 12
// Might need to move outside the class
istream& operator>>(istream &in, samplet<T> &a_samplet){
  char larrow;
  char colon;
  char rarrow;
  int size;
  vector <T> new_vec;

  if (in>> larrow){
    if(larrow == '<'){
      if (in>>size){
        if (in >> colon && colon == ':'){
          for(unsigned int i = 0; i!=size; i++){
            T input;
            in >> input;
            new_vec.push_back(input);
          }
          if(in >> rarrow && rarrow == '>'){
            a_samplet = samplet<T>(new_vec);
          }else (cout << "\nInvalid Input, try again.\n")<< endl;
        }
      }
    }
  }
  return in;
}

/* With generic code, it's the header (.h) that includes the source (.cc), not the other way around that is the normal practice with non-generic code. */
#include "samplet.cc"
#endif
