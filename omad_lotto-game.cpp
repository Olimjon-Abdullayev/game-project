#include <iostream>
#include <time.h>
using namespace std;

int main() {
   
   cout << "\n\n##########################################################\n";
   cout << "###################### OMAD LOTTO  #######################\n";
   cout << "##########################################################\n\n\n";
    int userNumbers[6];
    int computerNumbers[6];
    int correctGuesses = 0;

    cout << "Iltimos, 1 dan 36 gacha 6 ta raqam kiriting:\n";
    for (int i = 0; i < 6; i++) {
        cout <<(i+1)<<" - raqam: " ;
        cin >> userNumbers[i];
    }
 
    srand(time(0)); 
    for (int i = 0; i < 6; i++) {
        int randomNumber;
        bool isDuplicate;

        do {
            randomNumber = rand() % 36 + 1; 
                isDuplicate = false;

            for (int j = 0; j < i; j++) {
                if (randomNumber == computerNumbers[j]) {
                    isDuplicate = true;
                    break;
                }
            }
        } while (isDuplicate);

        computerNumbers[i] = randomNumber;
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (userNumbers[i] == computerNumbers[j]) {
                correctGuesses++;
                break;
            }
        }
    }

    
    cout << "\nKompyuter tomonidan generatsiya qilingan raqamlar: ";
    for (int i = 0; i < 6; i++) {
        cout << computerNumbers[i] << " ";
    }
    cout << endl;

    cout << "\n\nSiz " << correctGuesses << " ta raqamni tog'ri topdingiz.\n";

    
    if (correctGuesses == 6) {
        cout << "Tabriklaymiz! Siz g'olib bo'ldingiz!\n";
    } else if (correctGuesses == 5) {
        cout << "Siz 2-kategoriya g'olib bo'ldingiz!\n";
    } else if (correctGuesses == 3) {
        cout << "Siz 4-kategoriya g'olib bo'ldingiz!\n";
    } else {
        cout << "Siz yutqazdingiz :(  Qayta urinib ko'ring!\n";
    }

   int choice;
   cout << "\n\nYana qayta o'ynaysizmi?\n 1.Ha           2.Yo'q\n"; cin >>choice;

switch(choice){
    case 1:
main();
break;
    case 2:
break;
    default:
    cout << "\n\nFaqat 1 yoki 2ni tanlang!";
}
}