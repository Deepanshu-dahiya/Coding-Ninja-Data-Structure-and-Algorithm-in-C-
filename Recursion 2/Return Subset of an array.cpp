/*Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array.
 But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)
*/


#include <iostream>
using namespace std;
#include <string>

/***
You need to save all the subsets in the given 2D output array.
 And return the number of subsets(i.e. number of rows filled in output) from the given function.
In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don�t print the subsets, just save them in output.
***/
int subset(int input[], int n, int output[][20]) {
    // Write your code here
 if(n<=0) {
      output[0][0]=0;
      return 1;
  }

  int smallOutput = subset(input+1,n-1,output);
  for(int i=0;i<smallOutput;i++) {
      int col = output[i][0] +1;
     output[i+smallOutput][0] = col;
       output[i+smallOutput][1] = input[0];
      for(int j=2; j<col+1;j++) {
        output[i+smallOutput][j] = output[i][j-1] ;
      }

  }

  return 2*smallOutput;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

