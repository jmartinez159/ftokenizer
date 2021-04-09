#include "token.h"

token::token()
{
    data = "";
    dataType = 0;
}

token::~token()
{

}


token::token(string d, int dT)
{
    data = d;
    dataType = dT;
}

int token::type()
{
    return dataType;
}

string token::typeOfData()
{
    string message;

    if(dataType == 0)
         message = "Whitespace";

    else if(dataType == 1)
        message = "Punctuation";

    else if(dataType == 2)
        message = "Number";

    else if(dataType == 3)
        message = "Alphabet";

    else if(dataType == 4)
        message = "Operator";

    return message;
}

string token::stringData()
{
    return data;
}


