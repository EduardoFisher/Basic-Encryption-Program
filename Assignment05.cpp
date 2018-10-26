/***********************************************************************
 *  AUTHOR       : Eduardo Fisher
 *  Assignment 05: Ciper
 *  CLASS        : CS02
 *  SECTION      : MW: 7:00am – 8:25am F: 7:00am - 11:15am
 *  Due Date     : 10/13/2016
************************************************************************/
#include <iostream>
#include <string>
/************************************************************************
 *
 * PROGRAM DESCRIPTION
 *
 * Encrypts and Decrypts a word that the user inputs.
 *_______________________________________________________________________
 * This program accepts one word and if needed a 26 char. long string
 * in from a user, then will encrypt that word or decrypt that word
 * depending on what the user wants to do.
 *_______________________________________________________________________
 * INPUT:
 *   method     : Choice of encryption or decryption -> input from user.
 *   translation: Translation map if the user does not want to use
 *                the default translation map -> input from user.
 *   word       : The word that the wants encrypted or decrypted
 *                ->input from user.
 *
 * OUTPUT:
 *   word       : The encrypted or decrypted word that the user entered.
 ************************************************************************/

using namespace std;

int main()
{
    int position;       // CALC - Used to hold the position of the letter
                        // in the word to it can be replaced by the
                        // the letter or number of the same position
                        // in the translation map.
    int size;           // CALC - Used to hold the size of the word so
                        // it can be used later on down the line.
    bool encryption;    // CALC - Bool to check to see if encryption
                        // is even possible.
    bool decryption;    // CALC - Bool to check to see if decryption
                        // is even possible.
    string method;      // INPUT - The user will enter either the word
                        // "encryption" or "decryption" to choose which
                        // one the user wants to use.
    string translation; // INPUT/CALC - The user will enter either the
                        // word "default" in to the program into this
                        // if the user doesnt want to enter a 26 char.
                        // string into this program.
    string word;        // INPUT/CALC/OUPUT - The user entered word that
                        // will serve as the bases for this program the
                        // word the that user will enter will be rewriten
                         // by the end of the program.
    string alphabet;    // CALC - Used in the "Default" encryption and
                        // decryption to find the position of the letter.
    string map;         // CALC - "Default" encryption/decryption used if
                        // user doesnt want to make a map.

    //Used to set the alphabet and the translation map so they can be used.
    alphabet = "abcdefghijklmnopqrstuvwxyz";
    map = "zyxwvutsrqponmlkjihgfedcba";

    // output the class heading to the screen
    cout << "**********************************************************\n";
    cout << "   Programmed by: Eduardo Fisher\n";
    cout << "   CS02         : MW: 7:00am - 8:25am F: 7:00am - 11:15am\n";
    cout << "   Assignment 05: Ciper\n";
    cout << "**********************************************************\n";

    //Asks the user if he wants to encrypt or decrypt a word.
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;
    cout << endl;

    //If statement to check to see if the method is a valid option.
    if (method == "encryption")
    {
        cout << "What is the translation map(type 'default' to use "
                "default): ";
        cin >> translation;
        cout << endl;

        //If statement to check if the word entered by the user is
        //"default".
        if (translation == "default")
        {
            //default map used from here on out.
            cout << "What is the single word to translate: ";
            cin >> word;
            cout << endl;

            //Finds the size of the word entered.
            size = word.size();

            //Used to check if the word is all lower case letters.
            for(int i = 0; i < size; i++)
            {
                if(word.at(i) >= 'a' && word.at(i) <= 'z')
                {
                    //If the word is all lower case letters then the bool
                    //is true.
                    encryption = true;
                }
                else
                {
                    //If at one point its not lower the program will set
                    //the bool to false and break from the program.
                    encryption = false;
                    break;
                }
            }

            //Checks to see if encryption is even possible.
            if(encryption == true)
            {
                for(int i = 0; i < size; i++)
                {
                    //Finds the position of the word in the alphabet.
                    position = alphabet.find(word.at(i));
                    //Uses the poisition to find the corresponding letter
                    //in the default translation map.
                    word.at(i) = map.at(position);
                }
                cout << "Encrypted word: " << word << endl;
            }
            else
            {
                //Outputs if the word cannot be translated.
                cout << "Error: encryption cannot be performed.\n";
            }
        }
        else
        {
            //Checks to see if the user entered map is 26 char long.
            if (translation.size() == 26)
            {
                //User created map used from here on out.
                cout << "What is the single word to translate: ";
                cin >> word;
                cout << endl;

                //Finds the size of the word entered.
                size = word.size();

                //Used to check if the word is all lower case letters.
                for(int i = 0; i < size; i++)
                {
                    if(word.at(i) >= 'a' && word.at(i) <= 'z')
                    {
                        //If the word is all lower case letters then the
                        //bool is true.
                        encryption = true;
                    }
                    else
                    {
                        //If at one point its not lower the program will
                        //set the bool to false and break from the program.
                        encryption = false;
                        break;
                    }
                }

                //Checks to see if encryption is even possible.
                if(encryption == true)
                {
                    for(int i = 0; i < size; i++)
                    {
                        //Finds the position of the word in the alphabet.
                        position = alphabet.find(word.at(i));
                        //Uses the poisition to find the corresponding
                        //letter in the default translation map.
                        word.at(i) = translation.at(position);
                    }
                    cout << "Encrypted word: " << word << endl;
                }
                else
                {
                    //Outputs if the word cannot be translated.
                    cout << "Error: encryption cannot be performed.\n";
                }
            }
            else
            {
                //Outputs if the map size is not 26.
                cout << "Error: invalid translation map size.\n";
            }
        }
    }

    //If statement to check to see if the method is a valid option.
    else if (method == "decryption")
    {
        cout << "What is the translation map(type 'default' to use "
                "default): ";
        cin >> translation;
        cout << endl;
        //If statement to check if the word entered by the user is
        //"default".
        if (translation == "default")
        {
            //default map used from here on out.
            cout << "What is the single word to translate: ";
            cin >> word;
            cout << endl;

            //Finds the size of the word entered.
            size = word.size();

            //Used to check if the word is all lower case letters.
            for(int i = 0; i < size; i++)
            {
                if(word.at(i) >= 'a' && word.at(i) <= 'z')
                {
                    //If the word is all lower case letters then the bool
                    //is true.
                    decryption = true;
                }
                else
                {
                    //If at one point its not lower the program will set
                    //the bool to false and break from the program.
                    decryption = false;
                    break;
                }
            }
            //Checks to see if decryption is even possible
            if(decryption == true)
            {
                for(int i = 0; i < size; i++)
                {
                    //Finds the position of the word in the alphabet.
                    position = alphabet.find(word.at(i));
                    //Uses the poisition to find the corresponding
                    //letter in the default translation map.
                    word.at(i) = map.at(position);
                }
                cout << "Decrypted word: " << word << endl;
            }
            else
            {
                //Outputs if the word cannot be translated.
                cout << "Error: decryption cannot be performed.\n";
            }
        }
        else
        {
            //Checks to see if the user entered map is 26 char long.
            if (translation.size() == 26)
            {
                //User created map is used from here on out.
                cout << "What is the single word to translate: ";
                cin >> word;
                cout << endl;

                //Finds the size of the word entered.
                size = word.size();

                //Used to check if the word is all lower case letters.
                for(int i = 0; i < size; i++)
                {
                    if(word.at(i) >= 'a' && word.at(i) <= 'z')
                    {
                        //If the word is all lower case letters then the
                        //bool is true.
                        decryption = true;
                    }
                    else
                    {
                        //If at one point its not lower the program will
                        //set the bool to false and break from the program.
                        decryption = false;
                        break;
                    }
                }

                //Used to check if all the letters in the user entered word
                //is in the translation map that the user entered earlier.


                //Checks to see if decryption is even possible.
                if(decryption == true)
                {
                    for(int i = 0; i < size; i++)
                    {
                        //Finds the position of the word in the alphabet.
                        position = translation.find(word.at(i));
                        //Uses the poisition to find the corresponding
                        //letter in the default translation map.
                        word.at(i) = alphabet.at(position);
                    }
                    cout << "Decrypted word: " << word << endl;
                }
                else
                {
                    //Outputs if the word cannot be translated.
                    cout << "Error: decryption cannot be performed.\n";
                }
            }
            else
            {
                //Outputs if the word cannot be translated.
                cout << "Error: invalid translation map size.\n";
            }
        }
    }
    else
        //Outputs if the method choice is not valid.
        cout << "Error: invalid method choice.\n";
    return 0;
}


