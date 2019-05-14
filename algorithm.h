#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "libraries.h"
#include <algorithm.h>
#include <vector>
#include <numeric> //For accumulate operation

/*For all those who aspire to excel in competitive programming,
only having a knowledge about containers of STL is of less use till one is not aware what all STL has to offer.
STL has an ocean of algorithms, for all < algorithm > library functions : Refer here.

Some of the most used algorithms on vectors and most useful one’s in Competitive Programming are mentioned as follows :

Non-Manipulating Algorithms

sort(first_iterator, last_iterator) – To sort the given vector.
reverse(first_iterator, last_iterator) – To reverse a vector.
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements*/


void algorithmTest()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 20, 5, 23 ,42 , 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Vector is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    // Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());

    cout << "\nVector after sorting is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    // Reversing the Vector
    reverse(vect.begin(), vect.end());

    cout << "\nVector after reversing is: ";
    for (int i=0; i<6; i++)
        cout << vect[i] << " ";

    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);

    cout << "\nOccurrences of 20 in vector : ";

    // Counts the occurrences of 20 from 1st to
    // last element
    cout << count(vect.begin(), vect.end(), 20);

    // find() returns iterator to last address if
    // element not present
    find(vect.begin(), vect.end(), 5) != vect.end()?
                cout << "\nElement found":
                        cout << "\nElement not found";

    // Sort the array to make sure that lower_bound()
    // and upper_bound() work.
    sort(vect.begin(), vect.end());

    cout << "\nVector after sorting is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    // Returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);

    // Returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);

    cout << "\nThe lower bound 20 is at position: ";
    cout << q-vect.begin();

    cout << "\nThe upper bound 20 is at position: ";
    cout << p-vect.begin();

    // Delete second element of vector
    vect.erase(vect.begin()+1);
    n = sizeof(vect)/sizeof(vect[0]);

    cout << "\nVector after erasing the element: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    // sorting to enable use of unique()
    sort(vect.begin(), vect.end());

    cout << "\nVector before removing duplicate "
            " occurrences: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    // Deletes the duplicate occurrences
    vect.erase(unique(vect.begin(),vect.end()),vect.end());

    cout << "\nVector after deleting duplicates: ";
    for (int i=0; i< vect.size(); i++)
        cout << vect[i] << " ";

    // Initializing vector with array values
    int arr1[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n1 = sizeof(arr1)/sizeof(arr[0]);
    vector<int> vect1(arr, arr+n);

    cout << "\nGiven Vector is:\n";
    for (int i=0; i<n1; i++)
        cout << vect[i] << " ";

    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing next permutation:\n";
    for (int i=0; i<n1; i++)
        cout << vect[i] << " ";

    prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev permutation:\n";
    for (int i=0; i<n1; i++)
        cout << vect[i] << " ";

    // Return distance of first to maximum element
    cout << "\nDistance between first to max element: ";
    cout << distance(vect.begin(), max_element(vect.begin(), vect.end()));

    cout << endl;

}

#endif // ALGORITHM_H
