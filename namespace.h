#ifndef NAMESPACE_H
#define NAMESPACE_H
#include <libraries.h>

namespace mySpace {

    class MyNewLine
    {
        string text;
    public:
        MyNewLine(string text = "My text\n\n\n"){this->text = text;}
        string toString()
        {
            return text;
        }
    };

    ostream & operator<<(ostream &out, MyNewLine &obj)
    {
        return out << obj.toString();
    }
    MyNewLine endl;

}

#endif // NAMESPACE_H
