// Program Name: Baconian_Cipher.cpp
// Last Modification Date: 14/03/2022
// Purpose: This program is developed to encrypt or decrypt the message entered
// By the user using Baconian cipher after he choose an operation and display the Encrypted/Decrypted message
// on Screen

#include <iostream>
#include <string>

using namespace std;

void encryption(string s1,string s2 ,char arr1[],int c1,string arr2[],int c2)
{
    cout<<"\nPlease Enter The Message To Cipher:\n";

    getline(cin,s1);   // get the input

for (int i=0 ;i<s1.size();i++)
{
    if (islower(s1[i])){
        s1[i]-=32;
    }
    if (s1[i]==' '){

        s1.erase(i,1); // delete the spaces in the word
        i-=1;
    }
}
for (auto j : s1)
{
    for (int k=0;k<26;k++)
    {
        if(j==arr1[k]) // check if each letter in the input is in arr1
        {
            s2+=arr2[k];   // add the value equal to the letter from arr2 to s2
            s2+=' ';   // add space after each letter
        }
    }
}

cout<<s2<<endl<<endl<<endl;
}

void decryption(string s1,string s2,string decrypted ,char arr1[],int c1,string arr2[],int c2)
{

cout<<"\nPlease Enter The Message To Decipher:\n";
    getline(cin,s1);   // get the input


for (int i=0 ;i<s1.size();i++)
{
if (s1[i]==' ')
{
s1.erase(i,1);   // delete the spaces in the word
i-=1;
}
}
for (int x=0;x<s1.size();x+=5)
{
    for(int j=0;j<5;j++)
    {
        decrypted+=s1[j+x];  // adding 5 letters from input every time to decrypted
    }
    for(int m=0;m<26;m++)
    {
        if (decrypted==arr2[m]) {  // check if each letter in the input is in arr2
            s2+=arr1[m];   // adding the decrypted letter to s2
        }

    }
    decrypted="";  // empty the variable to the other values
}
cout<<s2<<endl<<endl<<endl;


}



int main(){

bool isAvailable = true;
char arr1 [26] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string arr2 [26]= {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};
string choice,token,returned,decrypted;


while (isAvailable){
    cout<<"\nWelcome To Cipher...\n\nWhat Do you Like To Do ?\n1- Cipher a Message\n2- Decipher a Message\n3- End\n>>> ";
    cin>>choice;    // get the choice form the user
    cin.ignore();


    if (choice=="1"){
        encryption(token,returned,arr1,26,arr2,26);  // going to function encryption
    }
    else if(choice=="2"){
        decryption(token,returned,decrypted,arr1,26,arr2,26);   // going to function decryption
    }
    else if (choice=="3"){
        cout<<"\n\nGood Bye Then ..! \n";      // closing the program
        isAvailable=false;
    }
    else{
        cout<<"\nSorry,Please enter a Valid Input.... \n";  // handling the error
    }
}
}




