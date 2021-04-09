#ifndef FTOKEN_H
#define FTOKEN_H
#include <iostream>
#include <fstream>
#include "tokenizer.h"


using namespace std;


/*
    - FileTokenizer will get a file name for the default constructor.
    - Next we work on getting input from the file and separate the text
      being fed in from the file
        - File needs to be opened
        - Use getline with delimiters to get blocks of text from file
        - Store input to textBlock, so we need to convert cstring and copy
          that on to textBlock string
        -



*/


class ftoken
{
public:



    ftoken(string file);

    ~ftoken();

    void getFileInput();

private:
    //Input from file
    ifstream inFile;

    //String to hold name of file
    string fileName;

    //tokenizer will break up individual blocks of text
    tokenizer stringTokenizer;

    string textBlock;

    string convertCString(char toCopy[], int size);

};

#endif // FTOKEN_H
