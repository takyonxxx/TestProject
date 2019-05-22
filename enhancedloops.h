#ifndef LOOPS_H
#define LOOPS_H
#include "libraries.h"
/*
Enhanced (Geliştirilmiş)
Range-based for loop in C++ is added since C++ 11.
It executes a for loop over a range.
Used as a more readable equivalent to the traditional for loop operating over a range of values,
such as all elements in a container.
for ( range_declaration : range_expression )
    loop_statement
*/

void testloops()
{
    // Printing string characters
    string str = "Geeks";
    for (auto c : str)
        cout << c << ' ';

    cout << endl;

    // Printing keys and values of a map
    map <int, int> MAP({{1, 1}, {2, 2}, {3, 3}});
    for (auto i : MAP)
        cout << '{' << i.first << ", "
             << i.second << "}\n";

    cout << endl;

}

#endif // LOOPS_H
