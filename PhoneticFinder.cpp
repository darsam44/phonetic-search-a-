#include <string>
#include <iostream>
using namespace std;

/*This function will find the word that we search with the mistakes that can be made */
string find(string text, string word){
    int i, j=0;
    string ans;
    while (text.at(i)!=EOF){
        if(text.at(i)==word.at(j)){
            i++;
            j++;
            ans+=text.at(i);
        }
        else{
            if(Same(text.at(i), word.at(j))){
                i++;
                j++;
                ans+=text.at(i);

            }
            else{
                if(mistake(text.at(i), word.at(j))){
                    i++;
                    j++;
                    ans+=text.at(i);
                }
            }
        }
    }



}

/*function that check if the letter is the same letter (capital or small)*/
bool Same(char let1, char let2){
    if(islower(let1) && isupper(let2)){
        let1=toupper(let1);
        if(let1==let2){
            return true;
        }
    }
    if(isupper(let1) && islower(let2)){
        let2=toupper(let2);
        if(let1==let2){
            return true;
        }
    }
    return false;
}

/* function that check if there is confuse between 2 letters */ 
bool mistake(char let1, char let2){
    if(char let1)
}