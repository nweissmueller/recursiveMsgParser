/* #########################################################
 * Personal Project: Parsing a message
 * Work by Nikolas Weissmueller (@nweissm)
 * Class: CS 106B, Summer Term, August 2022
 *
 * This cpp file provides functionality to recursively parse
 * a continuous string, constructed entirely of alphabet
 * lower case characters, and without space delimeters,
 * into all possibe combinations of valid words.
 *
 * Solutions 1 and 2 use recursive backtracking.
 *
 * Functionality test cases are provided.
 *
 * #########################################################
 */
#include <iostream>
#include "console.h"
#include "testing/SimpleTest.h"
using namespace std;

/*
 * This sample main brings up testing menu.
 */
int main() {
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }
    cout << "All done, exiting" << endl;
    return 0;
}
