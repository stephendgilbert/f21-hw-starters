/**
 *  @author Put your name here
 *  @date Put the date here
 *  @file h12.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "WHO AM I?"; // Add your Canvas/occ-email ID

// Write your function here
void strip()
{
    bool inString = false;      // not in a string
    bool inSingleCmt = false;   // not in a single-line comment
    bool inMultiCmt = false;    // not in a multi-line comment

    char ch;
    while (cin.get(ch))
    {
        if (inSingleCmt && ch == '\n') inSingleCmt = false;
        else if (inString && ch == '"') inString = false;
        else if (inString && ch == '\\' && cin.peek() == '"')
        {
            cout.put(ch);
            cin.get(ch);
        }
        else if (inMultiCmt && ch == '*' && cin.peek() == '/')
        {
            cin.get(ch);
            cin.get(ch);
            inMultiCmt = false;
        }
        else if (!inString && !inSingleCmt && !inMultiCmt)
        {
            if (ch == '"') inString = true;
            else if (ch == '/' && cin.peek() == '*') inMultiCmt = true;
            else if (ch == '/' && cin.peek() == '/') inSingleCmt = true;
        }
        if (cin && !inSingleCmt && !inMultiCmt)
            cout.put(ch);
    }
}


//////////////// STUDENT TESTING ////////////////////
int run()
{
    //cout << "Student testing" << endl;
    strip();
    return 0;
}