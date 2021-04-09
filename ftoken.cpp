#include "ftoken.h"

ftoken::ftoken(string file)
{
    fileName = file;
}

void ftoken::getFileInput()
{
    //Open file to recieve input
    inFile.open(fileName);

    string temp = "";

    //Have a loop to keep recieving information from file
    while(getline(inFile, temp)) //getline(inFile,temp)
    {
        temp += '\n';
        cout << temp << '|' <<endl;
        //Storing into textBlock as a string
        textBlock += temp;

    }
    stringTokenizer.setBlockString(textBlock);
    stringTokenizer.getWords();
    stringTokenizer.printList();

    inFile.close();
}

string ftoken::convertCString(char toCopy[], int size)
{
    string saved = "";
    for(int i = 0; i < size; i++)
    {
        if(toCopy[i] == '\0')
        {
            return saved;
        }
        saved += toCopy[i];
    }

    return saved;
}

