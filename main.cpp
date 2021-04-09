#include <iostream>
#include "ftoken.h"

using namespace std;

void testTokenizer();

int main(int argc, char *argv[])
{
   testTokenizer();

    return 0;
}

void testTokenizer()
{

    ftoken f("solitude.txt");
    f.getFileInput();
}


//  ' "
