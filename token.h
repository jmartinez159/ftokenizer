#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>

using namespace std;



//Token class is only keeping the identity of the string passed into it.
class token
{
public:

    //Constructor
    token();

    //This constructor initializes token data and dataType to the values
    //passed through its parameters.
    token(string data ,int dataType);

    ~token();

    //Member Functions

    //int type() - returns the value used to determine
    //             the data type of the token.
    int type();

    //string typeOfData() - returns what kind of data type the token has
    //                      via a string variable.
    string typeOfData();

    //string stringData() - returns the string stored in the token.
    string stringData();

private:
    string data;
    int dataType;

};

#endif // TOKEN_H
