#include "PhoneticFinder.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace phonetic {
    /*function that check if the letter is the same letter (capital or small)*/
    bool Same(char let1, char let2){
        if(islower(let1) && isupper(let2)){ 
            let1=toupper(let1);
            if(let1==let2){
                return true;
            }
        }
        else if(isupper(let1) && islower(let2)){
            let2=toupper(let2);
            if(let1==let2){
                return true;
            }
        }
        return false;
    }

/* function that check if there is confuse between 2 letters */ 
    bool mistake(char let1, char let2){
        let1=tolower(let1);
        let2=tolower(let2);
        switch(let1){
            // v, w
            case 'v': 
            case 'w':
            if( (let1=='v' && let2=='w') || (let1=='w' && let2=='v')){
                return true;
            }
            break;

            // b,f,p
            case 'b' :
            case 'f' :
            case 'p' :
            if((let1=='b' && let2=='p') || (let1=='p' && let2=='b')){
                return true;
            }
            if((let1=='b' && let2=='f') || (let1=='f' && let2=='b')){
                return true;
            }
            if((let1=='p' && let2=='f') || (let1=='f' && let2=='p')){
                return true;
            }
            break;

            //g,j
            case 'g': 
            case 'j':
            if( (let1=='g' && let2=='j') || (let1=='j' && let2=='g')){
                return true;
            }
            break;

            //c,k,q
            case 'c' :
            case 'k' :
            case 'q' :
            if((let1=='c' && let2=='k') || (let1=='k' && let2=='c')){
                return true;
            }
            if((let1=='c' && let2=='q') || (let1=='q' && let2=='c')){
                return true;
            }
            if((let1=='q' && let2=='k') || (let1=='k' && let2=='q')){
                return true;
            }
            break;

            //s,z
            case 's': 
            case 'z':
            if( (let1=='s' && let2=='z') || (let1=='z' && let2=='s')){
                return true;
            }
            break;

            //d,t
            case 'd': 
            case 't':
            if( (let1=='d' && let2=='t') || (let1=='t' && let2=='d')){
                return true;
            }
            break;

            //o,u
            case 'o': 
            case 'u':
            if( (let1=='o' && let2=='u') || (let1=='u' && let2=='o')){
                return true;
            }
            break;

            //i,y
            case 'i': 
            case 'y':
            if( (let1=='i' && let2=='y') || (let1=='y' && let2=='i')){
                return true;
            }
            break;
        
            default:
            return false;
        }
        return false;
    }


    /* This function will return the word that we search for , with all the mistakes */
	string find(string text, string word) {
        if (word == " "){
             throw out_of_range{" the word that you entered isn't valid"};
        }
        if ( word.size() == 0){
             throw out_of_range{" the word that you entered isn't valid"};
        }

        int i=0, j=0;
        string ans= "";
        while (i < text.size()){
            //if the word is finished
            if (j == word.size() && text.at(i) == ' ' ){
                break;
            }
            if ((j < word.size())){
                if( text.at(i)==word.at(j)){
                    ans+=text.at(i);
                    j++;
                }
                //if the words are the same but in capital / small letters
                else if(Same(text.at(i), word.at(j))){
                        ans+=text.at(i);
                        j++;
                }
                //if there was a mistake
                else if(mistake(text.at(i), word.at(j))){
                            ans+=text.at(i);
                            j++;
                }
                else {
                        j=0;
                        ans = "";
                        while (text.at(i) != ' '){
                            i++;
                        }
                }   
            }
            //last letter 
            else {
                    j=0;
                    ans = "";
                    while (text.at(i) != ' '){
                        i++;
                    }
            }  
            
            i++;     
        }
                
            //if we finish pass all the text
            if(i==text.size()){
                if(j==word.size()){
                    return ans;
                }
            }

            //if there is onlt space at the place 
            if ( (j==word.size()) && (text.at(i)==' ')){
                return ans;
            }
            else{
                    throw out_of_range{" The word that you enter didn't found in the text . "};
            }
    }
}

