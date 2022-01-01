/*You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively.
You need to print their intersection;
An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words,
when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1)..
*/


#include <iostream>
using namespace std;
#include <string>
#include<bits/stdc++.h>
void intersection(int *arr1, int *arr2, int n, int m)
{
    //Write your code here
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int i=0,j=0;

    while(i<n && j<m){
        if(arr1[i]==arr2[j]){

            cout<<arr1[i]<<" ";
        	 i++;
            j++;
        }
        if(arr1[i]<arr2[j]){
            i++;
        }
          if(arr1[i]>arr2[j]){
       		j++;
       }



    }


}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);

		delete[] input1;
		delete[] input2;

		cout << endl;
	}

	return 0;
}
