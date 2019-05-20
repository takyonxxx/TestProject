#ifndef VECTORS_H
#define VECTORS_H
#include "libraries.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <locale>
#include <clocale>


void replaceVectorElement(list<int> &lnumbers,  list<int>::iterator &rIt, int value);
void testVectors()
{
    vector<string> strings; //automaticaly allocate size, pre size can be problem
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    //iterator
    //vector<string>::iterator it = strings.begin(); // points first element
    //it++; // overload operator
    //cout << *it << endl;

    for (auto it = strings.begin(); it != strings.end(); it++) //const iterator can not change elements
    {
        cout << *it << endl;
    }

    //vectors and memory
    vector<double> numbers;
    int size = numbers.size(); // number of elements
    int capacity = numbers.capacity(); // capacity of vector
    cout << "First capacity: " << capacity << endl;

    for (int i = 0; i < 1000; i++)
    {
        if(numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            cout << "Next capacity: " << numbers.capacity() << endl; // exponentially increasing 1 2 4 8 16 ...
        }
        numbers.push_back(i);
    }

    /* numbers.clear(); // capacity will not change
    numbers.resize(100); // capacity will not change
    cout << "\nLast size: " << numbers.size() << endl;
    cout << "Last capacity: " << numbers.capacity() << endl;*/

    numbers.reserve(10000); // capacity will be change
    cout << "\nLast size: " << numbers.size() << endl;
    cout << "Last capacity: " << numbers.capacity() << endl;

    //two dimensional vector
    cout << "\nTwo dimensional vector:" << endl;

    vector<vector<int>> grid(3, vector<int>(4,7));
    grid[1].push_back(8);
    for (int row = 0;row < grid.size(); row++) {
        for (int col = 0;col < grid[row].size(); col++) {
            cout << grid[row][col] << flush;
        }
        cout << endl;
    }
    //output: not same size
    //7777
    //77778
    //7777

    //List : they have pointers to each other
    cout << "\nList:" << endl;
    list<int> lnumbers;
    lnumbers.push_back(1);
    lnumbers.push_back(2);
    lnumbers.push_back(3);
    lnumbers.push_front(0);

    auto it = lnumbers.begin();
    it++;
    lnumbers.insert(it, 100);// second element will be 100, insert it before the iterator element

    auto eraseIt = lnumbers.begin();
    eraseIt++;
    lnumbers.erase(eraseIt); // 100 will be erased

    //replacing element 1 with 1234
    cout << "replacing element 1 with 1234" << endl;
    auto rIt = lnumbers.begin();
    rIt++;
    rIt++;

    replaceVectorElement(lnumbers, rIt, 1234);

    for (auto it = lnumbers.begin(); it != lnumbers.end(); it++) {
        cout << *it << endl;
    }
}

void replaceVectorElement(list<int> &lnumbers,  list<int>::iterator &rIt, int value)
{
    for (auto it = lnumbers.begin(); it != lnumbers.end();)
    {

        if(it == rIt)
        {
            lnumbers.insert(it, value);
        }

        if(it == rIt)//delete old it
        {
            it = lnumbers.erase(it); // we should set it
        }

        it++;
    }

}

class TestPerson
{
    string name;
    int age;

public:

    TestPerson():name(""), age(0){}

    TestPerson(const TestPerson &other)// copy constructor
    {
        cout << "copy constructor running" << endl;
        name = other.name;
        age = other.age;
    }

    TestPerson(string name, int age):name(name), age(age)
    {
    }

    void print() const
    {
        cout << name << ": " << age << endl;
    }

    //overloading <
    bool operator<(const TestPerson &other) const{
        if(name == other.name){
            return age < other.age;
        }
        else {
            return name < other.name;
        }
    }

};

void testMaps()
{
    map<string, int> ages;
    ages["Turkay"] =  45;
    ages["Alya"] =  13;
    ages["Gokhan"] =  42;

    if(ages.find("Turkay") != ages.end())
    {
        cout << "Find:  Turkay. Age: " << ages["Turkay"] << endl;
    }
    else {
        cout << "Key not found..." << endl;
    }

    cout << endl;

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << endl;

    pair<string, int> addToMap ("Peter", 100);
    ages.insert(addToMap);

    ages.insert(make_pair("Aysen", 35));

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        pair<string, int> age = *it;
        cout << age.first << " " << age.second << endl;
    }

    cout << endl;

    map<int, TestPerson> people;
    people[0] = TestPerson("Turkay", 45);
    people[1] = TestPerson("Alya", 13);
    people[2] = TestPerson("Gokhan", 42);

    people.insert(make_pair(3, TestPerson("Aysen", 35)));

    for (auto it = people.begin(); it != people.end(); it++) {
        cout << it->first << ": " << flush;
        it->second.print();
    }

    cout << endl;

    map<TestPerson, int> people1;
    people1[TestPerson("Turkay", 45)] = 45;
    people1[TestPerson("Turkay", 444)] = 123;
    people1[TestPerson("Alya", 13)] = 13;
    people1[TestPerson("Gokhan", 42)] = 42;

    for (auto it = people1.begin(); it != people1.end(); it++) {
        cout << it->second << ": " << flush;
        it->first.print();
    }

    cout << endl;

    //multimap
    multimap<int, string> lookup;
    lookup.insert(make_pair(30, "Turkay"));
    lookup.insert(make_pair(10, "Alya"));
    lookup.insert(make_pair(30, "Gokhan"));
    lookup.insert(make_pair(20, "Ayla"));

    for (auto it = lookup.begin(); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    for (auto it = lookup.find(20); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    //pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
    auto its = lookup.equal_range(30);

    for (auto it = its.first; it != its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

class Test
{
    int id;
    string name;

public:

    Test(): id(0), name(""){}

    Test(int id, string name): id(id), name(name)
    {
    }

    void print() const
    {
        cout << id << ": " << name << endl;
    }

    //make the name unique
    bool operator<(const Test & other) const
    {
        if(name != other.name)
            return name < other.name;
        else
            return id < other.id;
    }
    friend bool comp(const Test &a, const Test &b);
    int getId() const{return id;}
};

bool comp(const Test &a, const Test &b)
{
    return a.id < b.id;
}

void testSet()
{
    set<int> numbers; // automaticaly sort numbers
    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(20);

    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    cout << endl;

    auto itFind = numbers.find(30);
    if(itFind != numbers.end())
    {
        cout << "Found: " <<  *itFind << endl;
    }

    if(numbers.count(30))
    {
        cout << "Number 30 found" << endl;
    }

    set<Test> tests; // automaticaly sort numbers
    tests.insert(Test(10, "Turkay"));
    tests.insert(Test(30, "Gokhan"));
    tests.insert(Test(50, "Gokhan"));
    tests.insert(Test(20, "Alya"));


    for (auto it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }
}

void testSort()
{
    vector<Test> tests;
    tests.push_back(Test(5, "Turkay"));
    tests.push_back(Test(10, "Alya"));
    tests.push_back(Test(7, "Gokhan"));
    tests.push_back(Test(3, "Muteber"));

    sort(tests.begin(), tests.end());

    for (auto it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }

    cout << endl;

    auto itemId = 7;
    auto itrA = std::find_if(tests.begin() , tests.end() , [&itemId](Test entry){
            return entry.getId() == itemId;
});

    if(itrA != tests.end())
    {
        itrA->print();
    }

    itemId = 8;
    auto found = std::any_of(tests.begin() , tests.end() , [&itemId](Test entry){
            return entry.getId() == itemId;
});

    cout << found << endl;

    map<string, vector<int> > scores;
    scores["Turkay"].push_back(10);
    scores["Alya"].push_back(9);
    scores["Gokhan"].push_back(2);
    scores["Turkay"].push_back(7);

    for (auto it = scores.begin(); it != scores.end(); it++)
    {
        auto name = it->first;
        auto scoreList = it->second;

        cout << name << ": " << flush;

        for (auto i = 0; i < scoreList.size(); i++)
        {
            cout << scoreList[i] << " " << flush;
        }
        cout << endl;
    }
}

#endif // VECTORS_H

