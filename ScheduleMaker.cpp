/******************************************************************************

Diego L. de los Reyes
Jared Harris
Started: 2/15/2022
Ended: 2/19/2022
Schedule Maker

*******************************************************************************/
// Include statments
#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <time.h>
using namespace std;

int main()
{
    // Seed
    srand (time(NULL));
    
    // Initialize schedule
    static int numShifts = 4;
    static int days = 25;
    int schedule[numShifts][days];
    
    // Emptying schedule
    for (int i = 0; i < numShifts; i++) {
        for (int j = 0; j < days; j++) {
            schedule[i][j] = 0;
        }
    }
    
    /* Off days of everyone
    1: Liz
    2: Brimah
    3: Carla
    4: Diego
    5: Ash
    6: Xander*/
    int off1[] = {0, 4, 5, 6, 17, 18, 23};
    int off2[] = {4, 6, 12, 13, 20};
    int off3[] = {0, 11, 12, 16, 19};
    int off4[] = {3, 9, 13, 18, 20};
    int off5[] = {3, 8, 15, 16, 22};
    int off6[] = {5, 8, 15, 17, 22};
    
    //Day 0 (keeping 2/20 from OG schedule)
    schedule[0][0] = 6;
    schedule[1][0] = 4;
    schedule[2][0] = 5;
    schedule[3][0] = 2;
    
    int offCounter1 = 1;
    int offCurrent1 = 0;
    bool available1 = true;
    
    int offCounter2 = 0;
    int offCurrent2 = 0;
    bool available2 = true;
    
    int offCounter3 = 1;
    int offCurrent3 = 0;
    bool available3 = true;
    
    int offCounter4 = 0;
    int offCurrent4 = 0;
    bool available4 = true;
    
    int offCounter5 = 0;
    int offCurrent5 = 0;
    bool available5 = true;
    
    int offCounter6 = 0;
    int offCurrent6 = 0;
    bool available6 = true;
    
    int person = 0;
    bool picked = false;
    /*outer loop
    check availability
    inner loop
    populate
    reset availability for next day*/
    
    // Shift counter initialize
    static int numWorkers = 6;
    int countShift[numShifts][numWorkers];
    // Empty shift counter
    for (int i = 0; i < numShifts; i++) {
        for (int j = 0; j < numWorkers; j++) {
            countShift[i][j] = 0;
        }
    }
    
    // Day "0" shift count addition
    countShift[0][5]++;
    countShift[1][3]++;
    countShift[2][4]++;
    countShift[3][1]++;
    
    // Shift counter before the do while
    int shiftACount = 0;
    int shiftBCount = 0;
    int shiftCCount = 0;
    int shiftDCount = 0;
    
    bool shiftADone = false;
    bool shiftBDone = false;
    bool shiftCDone = false;
    bool shiftDDone = false;
    
    int iterations = 0;
    
    do {
        shiftACount = 0;
        shiftBCount = 0;
        shiftCCount = 0;
        shiftDCount = 0;
        
        shiftADone = false;
        shiftBDone = false;
        shiftCDone = false;
        shiftDDone = false;
        
        for (int i = 0; i < numShifts; i++) {
            for (int j = 0; j < numWorkers; j++) {
                countShift[i][j] = 0;
            }
        }
        countShift[0][5]++;
        countShift[1][3]++;
        countShift[2][4]++;
        countShift[3][1]++;
        
        // Make the schedule
        for (int i = 1; i < days; i++) {
            // Check availability of people
            offCurrent1 = off1[offCounter1];
            offCurrent2 = off2[offCounter2];
            offCurrent3 = off3[offCounter3];
            offCurrent4 = off4[offCounter4];
            offCurrent5 = off5[offCounter5];
            offCurrent6 = off6[offCounter6];
            if (offCurrent1 == i) {
                available1 = false;
                offCounter1++;
            }
            if (offCurrent2 == i) {
                available2 = false;
                offCounter2++;
            }
            if (offCurrent3 == i) {
                available3 = false;
                offCounter3++;
            }
            if (offCurrent4 == i) {
                available4 = false;
                offCounter4++;
            }
            if (offCurrent5 == i) {
                available5 = false;
                offCounter5++;
            }
            if (offCurrent6 == i) {
                available6 = false;
                offCounter6++;
            }
            // Populate
            for (int j = 0; j < numShifts; j++) {
                picked = false;
                do {
                    person = rand() % 6 + 1;
                    switch (person) {
                        case 1:
                        // && (schedule[j][i-1] != person)
                            if (available1) {
                                if (j != 0) {
                                    schedule[j][i] = person;
                                    available1 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else if (j == 0 && schedule[j][i-1] != person) {
                                    schedule[j][i] = person;
                                    available1 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else {
                                    break;
                                }
                            }
                            break;
                        case 2:
                            if (available2) {
                                if (j != 0) {
                                    schedule[j][i] = person;
                                    available2 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else if (j == 0 && schedule[j][i-1] != person) {
                                    schedule[j][i] = person;
                                    available2 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else {
                                    break;
                                }
                            }
                            break;
                        case 3:
                            if (available3) {
                                if (j != 0) {
                                    schedule[j][i] = person;
                                    available3 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else if (j == 0 && schedule[j][i-1] != person) {
                                    schedule[j][i] = person;
                                    available3 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else {
                                    break;
                                }
                            }
                            break;
                        case 4:
                            if (available4) {
                                if (j != 0) {
                                    schedule[j][i] = person;
                                    available4 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else if (j == 0 && schedule[j][i-1] != person) {
                                    schedule[j][i] = person;
                                    available4 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else {
                                    break;
                                }
                            }
                            break;
                        case 5:
                            if (available5) {
                                if (j != 0) {
                                    schedule[j][i] = person;
                                    available5 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else if (j == 0 && schedule[j][i-1] != person) {
                                    schedule[j][i] = person;
                                    available5 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else {
                                    break;
                                }
                            }
                            break;
                        case 6:
                            if (available6) {
                                if (j != 0) {
                                    schedule[j][i] = person;
                                    available6 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else if (j == 0 && schedule[j][i-1] != person) {
                                    schedule[j][i] = person;
                                    available6 = false;
                                    picked = true;
                                    countShift[j][person-1]++;
                                }
                                else {
                                    break;
                                }
                            }
                            break;
                        default:
                            cout << "WTF";
                            break;
                    }
                } while(picked == false);
            }
            available1 = true;
            available2 = true;
            available3 = true;
            available4 = true;
            available5 = true;
            available6 = true;
        }
        
        // Actually check shift numbers
        for (int i = 0; i < numWorkers; i++) {
            if (countShift[0][i] >= 4 && countShift[0][i] <= 6) shiftACount++;
        }
        for (int i = 0; i < numWorkers; i++) {
            if (countShift[1][i] >= 4 && countShift[0][i] <= 6) shiftBCount++;
        }
        for (int i = 0; i < numWorkers; i++) {
            if (countShift[2][i] >= 3 && countShift[0][i] <= 6) shiftCCount++;
        }
        for (int i = 0; i < numWorkers; i++) {
            if (countShift[3][i] >= 3 && countShift[0][i] <= 6) shiftDCount++;
        }
        
        if (shiftACount == 6) shiftADone = true;
        if (shiftBCount == 6) shiftBDone = true;
        if (shiftCCount == 6) shiftCDone = true;
        if (shiftDCount == 6) shiftDDone = true;
        
        iterations++;
        
    } while (!(shiftADone && shiftBDone && shiftCDone && shiftDDone));
    
    // Print schedule
    for (int i = 0; i < numShifts; i++) {
        for (int j = 0; j < days; j++) {
            cout << schedule[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Print shift counter
    for (int i = 0; i < numShifts; i++) {
        for (int j = 0; j < numWorkers; j++) {
            cout << countShift[i][j] << " ";
        }
        cout << endl;
    }
    
    //Print iterations
    cout << endl << "Number of attempts to make schedule: "
    << iterations << endl;
    
    return 0;
}