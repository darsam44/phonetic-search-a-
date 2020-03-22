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
        case 'v': 
        case 'w':
        if( (let1=='v' && let2=='w') || (let1=='w' && let2=='v')){
            return true;
        }
        break;

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

        case 'g': 
        case 'j':
        if( (let1=='g' && let2=='j') || (let1=='j' && let2=='g')){
            return true;
        }
        break;

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

        case 's': 
        case 'z':
        if( (let1=='s' && let2=='z') || (let1=='z' && let2=='s')){
            return true;
        }
        break;

        case 'd': 
        case 't':
        if( (let1=='d' && let2=='t') || (let1=='t' && let2=='d')){
            return true;
        }
        break;

        case 'o': 
        case 'u':
        if( (let1=='o' && let2=='u') || (let1=='u' && let2=='o')){
            return true;
        }
        break;

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
    /*This function will find the word that we search with the mistakes that can be made */

	std::string find(std::string text, std::string word) {
    int i=0, j=0;
    string ans= "";
    while (i < text.size() && j < word.size()){
        if(text.at(i)==word.at(j)){
            ans+=text.at(i);
            j++;
        }
        else if(Same(text.at(i), word.at(j))){
                ans+=text.at(i);
                j++;
            }
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
                            i++;     
            }
            
           
            if(i==text.size()){
               if(j==word.size()){
                   return ans;
               }
            }
        if ( (j==word.size()) && (text.at(i)==' ')){
            return ans;
        }
    else{
        throw std::out_of_range{" The word that you enter didn't found in the text . "};
    }
}
}

// int main(){
//     string a="Dond vorri be haffy" , b ="happy";
//     std:: cout << phonetic::find(a,b) << endl; 
//     try{
//         std:: cout << phonetic::find("Dond vorri be haffy","the") << endl; 
//     }
//     catch(exception ex){
//         cout << "   caught exception: " << ex.what() << endl;

//     }

    /*
    std:: cout<<Same('C','c') << endl;
        if (Same('b','f') ){
            std:: cout<<"false" << endl;
        }

    std:: cout<<Same('b','f') << endl;
    if (Same('W','w') ){
    std:: cout<< "true" << endl;
    }
*/
// }