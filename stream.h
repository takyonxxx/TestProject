#ifndef STREAM_H
#define STREAM_H
#include "libraries.h"

#include <fstream>

//put in from keyboard - source
//put out to file - destination

auto sizeOfFile(fstream *file)
{
    file->seekg(0, ios::end);
    auto fileOfSize = file->tellg();
    file->seekg(0, ios::beg);
    return static_cast<int>(fileOfSize);
}

bool areFilesEqual(fstream *a, fstream* b)
{
    int size1 = sizeOfFile(a);
    int size2 = sizeOfFile(b);

    if(size1 == size2)
    {
        int size;

        if(size1 > 1024)
            size = 1024;
        else
            size = size1;

        char *buffer1 = new char[size];
        char *buffer2 = new char[size];

        do
        {
            a->read(buffer1, size);
            b->read(buffer2, size);
            if(memcmp(buffer1, buffer2, size) != 0)
            {
                delete []buffer1;
                delete []buffer2;
                return false;
            }
        }while(a->good() && b->good());

        delete []buffer1;
        delete []buffer2;

        return true;
    }
}

void writeFile()
{
    fstream file;
    file.open("sample.txt",  ios::out | ios::binary); // create file
    if(file.is_open())
    {
      char sample[] = "line1\n";
      file.write(sample, sizeof (sample) - 1);//remove null by -1
    }
    else {
        cout << "The file hasn't been opened properly" << endl;
    }

    file.close();
}


void openFile()
{
    fstream file;
    file.open("sample.txt",  ios::in | ios::binary );
    if(file.is_open())
    {
        /* char first, second;
        do
        {
            first = file.get();
            file.ignore(40, ' ');
            second = file.get();
            file.ignore(40, '\n');
            cout << first << " " << second << endl;

        }while(!file.eof());*/

       /* auto size = sizeOfFile(&file);
        char *buffer = new char[size];
        file.read(buffer, size);
        cout << buffer << endl;
        delete []buffer;*/

        char buffer[250];
        do
        {
            file.getline(buffer, 250, '\n');
            cout << buffer << " " << file.gcount() << endl;

        }while(!file.eof());

        /*if((file.rdstate() ^ ifstream::eofbit) == 0)
            file.clear();*/

    }
    else {
        cout << "The file hasn't been opened properly" << endl;
    }

    file.close();
}

#endif // STREAM_H
