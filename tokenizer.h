#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "token.h"
#include <string.h>
#include <vector>




//Tokenizer takes in a block of texts and returns a list of tokens that contain
//each word and it's type(word, punctuation, number, or blankspace).
/* - Give tokenizer a string and/or cstring (these strings are expected to be
 *   complete sentences or phrases.)
 * - Initialize tokenizer cstring to the input string (stringPostion is at 0)
 * - Extract individual words from the input string
 *      - Traverse through the string going character by character
 *      - Traversing should pause at the end of a word, number, or sentence
 *      - (Going to have special cases for example "scooby, dooby, and doo"
 *         because of the punctuation characters)
 *      - stringPostion should be saved when traversing pauses so it can be
 *        easier to resume traversal
 *      - When strings are extracted they will be given a type to determine
 *        the type of string we have(number, word, punctuation, or whitespace).
 *      - Corner cases: Mr. Jorge is great. 30.12, app|les
 *      - string temp = "testing"; temp[2] // s
*/
class tokenizer
{
public:
    tokenizer();

    tokenizer(string inputBlock);

    ~tokenizer();

    void setBlockString(string input);

    void getWords();

    void printList();

    void clearList();


private:
    //String
    string block;

    //Storage of the words that were parsed
    vector<token> list;

    //Private member functions

    //This function's job is to determine what type of string we are
    //currently extracting.
    int stringType(char sample);

    bool isDelim(char x);


    bool isDecimal(int index, char theDelim);

    // '
    string belongsTo();

};

#endif // TOKENIZER_H
