#include <iostream>
using namespace std;
#include <math>

// To execute C++, please define "int main()"

void print_matrix(int dim)
{
  if(dim > 0) // error check
  {
    int num_spaces = num_digits(dim);
    for(int i = 0; i < dim; i++)
    {
        //num_digits() returns number of digits in dim.
        
        for(int j = 0; j < dim; j++)
        {
            int val = (i+1)*(j+1);
            int spaces = num_spaces - num_digits(val);
            for(int k = 0; k < spaces; k++)
              cout << " ";
            cout << val;  
          
        }
      cout << endl;
    }
  }
  return;
}

int num_digits(int x)
{
  return floor (log10 (abs (x))) + 1;
}

int main() {
  for (int i = 0; i < 5; i++) {
    //cout << "Hello, World\n";
  }
  print_matrix(10);
  return 0;
}



/* 


n

method(4)

4 * 4

 1  2  3  4
 2  4  6  8
 3  6  9 12
 4  8 12 16
 
 
 
 */
 