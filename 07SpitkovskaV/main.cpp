//written by Spitkovska
#include "Screen.h"
#include <iostream>
using namespace std;


int main() {
    int w = 22, h = 10;
    char text[] = "Let's fill the screen with something";
    Screen screen0(w, h, text);
    screen0.show();

    //making some changes in the lower part of code 

    screen0.move(14, 1).set('?').show();
    //printing out some symbols
    for (int i = 10; i < 22; i++)
    {
        screen0.move(i, 0).showCurrent();
    }

    //let's define some functions (const or non-const) we can call out
    const NonConstAction funcs[] = { &Screen::home, &Screen::show ,&Screen::move, &Screen::back, &Screen::clear};
    const ConstAction funcsConst[] = { &Screen::home, &Screen::move, &Screen::back,  &Screen::showCurrent , &Screen::show};

    //let's test in more interactive form
    char input;
    Screen screen(w, h, text); // Common screen for both const and non-const methods

    while (true) {
        //for non-const methods
        do {
            int iterations;
            int callID;

            screen.show();

            cout << "Enter the next step (0 - Go Home; 1 - Show; 2 - Forward; 3 - Back; 4 - Clear; 5 - Quit) << ";
            cin >> callID;

            if (callID == 5) {
                return 0;
            }

            while (callID < 0 || callID > 5) {
                cout << "Step ID has to be from 0 to 4. Try again <<  ";
                cin >> callID;
            }

            cout << "How many times? ";
            cin >> iterations;

            while (iterations <= 0) {
                cout << "Must be more than 0: ";
                cin >> iterations;
            }

            task(screen, iterations, funcs[callID]);

            if (callID == 4)
            {
                char ref;
                cout << "Refill empty screen? ( 0 - Yes; 1 - No) << ";
                cin >> ref;
                if (ref == '0')
                {
                    int startX = (w - 8) / 2; 
                    int startY = (h - 4) / 2;
                    for (int i = 0; i < h; ++i) 
                    {
                        for (int j = 0; j < w; ++j) 
                        {
                            if (i >= startY && i < startY + 4 && j >= startX && j < startX + 8) screen.move(j, i).set('*');
                        }
                    }
                }
            }
            cout << endl << "Continue here? (0 - Yes; 1 - No) <<  ";
            cin >> input;
        } while (input == '0');

        // for const methods
        do {
            int callID;
            int iterations;

            screen.show();

            cout << "Enter the next step (0 - Go Home; 1 - Forward; 2 - Back; 3 - Show Current; 4 - Show All; 5 - Quit) << ";
            cin >> callID;

            if (callID == 5) {
                return 0;
            }

            // check if task id is in the list
            while (callID < 0 || callID > 5) {
                cout << "Step ID has to be from 0 to 4. Try again: ";
                cin >> callID;
            }

            cout << "How many times? ";
            cin >> iterations;

            while (iterations <= 0) {
                cout << "Must be more than 0: ";
                cin >> iterations;
            }

            taskConst(screen, iterations, funcsConst[callID]);
            cout << endl << "Continue here? (0 - Yes; 1 - No): ";
            cin >> input;
        } while (input == '0');
    }
    return 0;
}
