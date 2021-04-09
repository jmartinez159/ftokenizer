#include "tokenizer.h"

// The number of code positions separating any given capital letter from its corresponding lower-case letter is 32.

tokenizer::tokenizer()
{

}

tokenizer::tokenizer(string inputBlock)
{
    block = inputBlock;
}

void tokenizer::setBlockString(string input)
{
    block = input;
}

void tokenizer::getWords()
{
    string value;
    int valueType;
    for(int i = 0; i < block.size(); i++)
    {

        //Checks to see if it is a delimiter at position i
        if(isDelim(block[i]) && !isDecimal(i, block[i]))
        {

            if(!value.empty()){

                //Find Type of string value is.
                valueType = stringType(value[0]);

                //Special case: | 's | at the end of the words is not being read in correctly
                //              inFile recieves character ' as a garbage value so I want to find
                //              the case that s is parsed by itself and add it to prev string in list
//                if(value.size() == 1 && value == "s")
//                {
//                    value = belongsTo();
//                }

                //Add token into our list by initializing token to
                //our variables extracted from block string
                list.push_back(token (value, valueType));
                value = "";
            }
        }

        //Just adds the next character to the string if not a delimiter
        else
        {
            value += block[i];
        }
    }

    //If string ends without a delimiter this checks to see if we have another
    //word left
    if(!value.empty())
    {
        //value += '\0';
        list.push_back(token (value, valueType));
        value = "";
    }
    return;
}


//Checks to see if input is a possible decimal number
bool tokenizer::isDecimal(int index, char theDelim)
{
    char nextChar;
    string numbs = "0123456789";
    string keyDelim = ".,";

    //Checks to see if there is one more
    if(index +1 <= block.size())
    {
        nextChar = block[index +1];

        //The next character if a decimal number should always be a number
        //if not then it is not a decimal number
        if(keyDelim.find(theDelim) != string::npos &&
           numbs.find(nextChar) != string::npos)
        {
            return true;
        }


     }

    return false;
}


//Checks if the parameter is a delimiter
bool tokenizer::isDelim(char x)
{

    //    string reverseDelim = "0129456789";
    //    reverseDelim += "ABCDEGFHIJKLMNOPQRSTUVWXYZ";
    //    reverseDelim += "abcdefghijklmnopqrstuvwxyz";

    //    if(reverseDelim.find(x) == string::npos)
    //    {
    //        return true;
    //    }



    //    return false;

    string Limit = " .!,?;:()\n\t\"";
    Limit += 34;
    if(Limit.find(x) != string::npos)
    {
        return true;
    }

    return false;
}

void tokenizer::printList()
{
    int count = 1;
    if(list.empty())
    {
        cout << "List is empty" <<endl;
        return;
    }

    for(int i = 0; i < list.size(); i++)
    {
        cout << list[i].stringData() << "|" << count++ <<endl;
    }

    cout << "List Size: " << list.size() <<endl;
    return;
}

int tokenizer::stringType(char sample)
{
    //keeps ascii value of the character being passed in
    int sampleValue = sample;

    //To check if sample is a number
    string numbs = "0123456789";


    //checks for alphabet using ascii values
    if(sampleValue >= 65 && sampleValue <= 90)
    {
        return 3;
    }

    //checks for alphabet
    if(sampleValue >= 65+32 && sampleValue <= 90+32)
    {
        return 3;
    }

    //checks for number
    if(numbs.find(sample) != string::npos)
    {
        return 2;
    }

    return 0;
}

void tokenizer::clearList()
{
    list.clear();
    return;
}

string tokenizer::belongsTo()
{
    string added;
    added = list[list.size() -1].stringData();
    added += "'s";
    list.pop_back();
    return added;
}

