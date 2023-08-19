// FCAI - Structured Programming - 2022 - Assignment 2
// Program Name: Baconian_Cipher.cpp
// Last Modification Date: 19/08/2023
// Author: Eslam Amin
// Purpose: This program is developed to encrypt or decrypt the message entered
// By the user using Baconian cipher after he chooses an operation and display the Encrypted/Decrypted message
// on Screen

#include <iostream>
#include <string>
#include<map>

using namespace std;

string encrypt(map<char, string> &dict) {
    cout << "\nPlease Enter The Message To Cipher:\n";
    string result, taken;
    cin.ignore();
    getline(cin, taken);   // get the input

    for (char &letter: taken) {
        if (!isspace(letter)) {
            result += (dict[toupper(letter)]); //pushing the matched value from the dict
            result += ' ';
        }
    }
    return result;
}

string decrypt(map<char, string> &dict) {

    cout << "\nPlease Enter The Message To Decipher:\n";
    string result, taken;
    cin.ignore();
    getline(cin, taken);   // get the input

    string temp;
    for (char &letter: taken) {
        if (!isspace(letter)) {
            temp += letter;
        } else {
            if (!temp.empty()) {
                for (auto &pair: dict) {
                    if (pair.second == temp) {
                        result += pair.first;
                        break;
                    }

                }
                temp.clear();
            }
        }
    }
    for (auto &pair: dict) {
        if (pair.second == temp) {
            result += pair.first;
            break;
        }
    }
    return result;
}


int main() {
    map<char, string>
            dictionary = {
            {'A', "aaaaa"},
            {'B', "aaaab"},
            {'C', "aaaba"},
            {'D', "aaabb"},
            {'E', "aabaa"},
            {'F', "aabab"},
            {'G', "aabba"},
            {'H', "aabbb"},
            {'I', "abaaa"},
            {'J', "abaab"},
            {'K', "ababa"},
            {'L', "ababb"},
            {'M', "abbaa"},
            {'N', "abbab"},
            {'O', "abbba"},
            {'P', "abbbb"},
            {'Q', "baaaa"},
            {'R', "baaab"},
            {'S', "baaba"},
            {'T', "baabb"},
            {'U', "babaa"},
            {'V', "babab"},
            {'W', "babba"},
            {'X', "babbb"},
            {'Y', "bbaaa"},
            {'Z', "bbaab"}

    };
    string result;
    int choice;
    do {
        cout << "\nWelcome To Cipher..."
                "\n\nWhat Do you Like To Do ?"
                "\n1- Cipher a Message"
                "\n2- Decipher a Message"
                "\n3- End" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                result = encrypt(dictionary);
                cout << result << '\n';
                break;
            }
            case 2: {
                result = decrypt(dictionary);
                cout << result << '\n';
                break;
            }
            case 3: {
                cout << "\nGood Bye Then ..! \n";
                break;
            }
            default:
                cout << "Enter a Valid choice, please :)\n";
                break;
        }

    } while (choice != 3);
}