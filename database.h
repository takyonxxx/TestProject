#ifndef DATABASE_H
#define DATABASE_H
#include "libraries.h"
#include <conio.h> // getch
#include <fstream>

struct Person
{
    string name;
    string surname;
    short age;
    string telephone;
};

Person people[20];
short peopleInDataBase = 0;

void requireEnter()
{
     cout << "Click Enter to continue..." << endl;
     while(getch() != 13);// require enter
}

void savePeopleToFile()
{
    ofstream file("database.txt");
    if(file.is_open())
    {
        file << peopleInDataBase << endl;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            file << (i+1) << endl;
            file << people[i].name << endl;
            file << people[i].surname << endl;
            file << people[i].age << endl;
            file << people[i].telephone << endl;
        }

        file.close();
    }
    else {
        cout << "The file hasn't been opened properly" << endl;
    }

}

void loadPeopleFromFile()
{
    ifstream file("database.txt");
    if(file.is_open())
    {

        file >> peopleInDataBase;
        if(peopleInDataBase > 0)
        {

            for (int i = 0; i < peopleInDataBase; i++)
            {
                file >> people[i].name;
                file >> people[i].surname;
                file >> people[i].age;
                file >> people[i].telephone;
            }

            cout << "People has been loaded properly."  << endl;
        }
        else {
            cout << "Database is empty..."  << endl;
        }

        file.close();
    }
    else {
        cout << "The file hasn't been opened properly" << endl;
    }
}

void searchDatabase()
{
    if(peopleInDataBase > 0)
    {
        string name;
        cout << "Type a name: ";
        cin >> name;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            if(name == people[i].name)
            {
                cout << "Person index: " << (i+1) << endl;
                cout << "Name: " << people[i].name << endl;
                cout << "Surname: " << people[i].surname << endl;
                cout << "Age: " << people[i].age << endl;
                cout << "Telephone: " << people[i].telephone << endl << endl;
            }
        }
    }
    else {
        cout << "Database is empty..."  << endl;
    }
}

void removeFromDatabase()
{
    if(peopleInDataBase > 0)
    {
        short index;
        cout << "Type index: ";
        cin >> index;

        if(peopleInDataBase >= index)
        {
            for (int k = index; k < peopleInDataBase; k++)
            {
                people[k-1].name = people[k].name;
                people[k-1].surname = people[k].surname;
                people[k-1].age = people[k].age;
                people[k-1].telephone = people[k].telephone;
            }
            peopleInDataBase--;
            savePeopleToFile();
        }
        else {
             cout << "There is nobody like that..."  << endl;
        }
    }
    else {
        cout << "Database is empty..."  << endl;
    }
}


void addPerson()
{
    cout << "Type name: " << endl;
    cin >> people[peopleInDataBase].name;

    cout << "Type surname: " << endl;
    cin >> people[peopleInDataBase].surname;

    cout << "Type age: " << endl;
    cin >> people[peopleInDataBase].age;

    cout << "Type telephone: " << endl;
    cin >> people[peopleInDataBase].telephone;

    peopleInDataBase++;
}

void showPeople()
{
    if(peopleInDataBase > 0)
    {
        for (int i = 0; i < peopleInDataBase; i++)
        {
            cout << "Person index: " << (i+1) << endl;
            cout << "Name: " << people[i].name << endl;
            cout << "Surname: " << people[i].surname << endl;
            cout << "Age: " << people[i].age << endl;
            cout << "Telephone: " << people[i].telephone << endl << endl;
        }
    }
    else {
        cout << "Database is empty..."  << endl;
    }
}

void databaseMenu()
{
    char test;

    loadPeopleFromFile();

    do
    {
        cout << "Number of people in Database: " << peopleInDataBase << endl;
        cout << "MENU: " << endl;
        cout << "1. Add Person" << endl;
        cout << "2. Show All People" << endl;
        cout << "3. Save People to File" << endl;
        cout << "4. Load People from File" << endl;
        cout << "5. Search for a Person" << endl;
        cout << "6. Remove Person from Database" << endl << endl;

        test = getch();

        switch (test)
        {
        case '1':
            addPerson();
            break;
        case '2':
            showPeople();
            break;
        case '3':
            savePeopleToFile();
            break;
        case '4':
            loadPeopleFromFile();
            break;
        case '5':
            searchDatabase();
            break;
        case '6':
            removeFromDatabase();
            break;
        default:
            break;
        }

        requireEnter();
        system("cls");
    }while(test != 27);//esc char

}

#endif // DATABASE_H
