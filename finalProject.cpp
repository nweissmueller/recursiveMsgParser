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
 * Solution 1: Recursive backtracking and pass by reference.
 *
 * Functionality test cases are provided.
 *
 * #########################################################
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "strlib.h"
#include "vector.h"
#include <string>
#include "lexicon.h"
#include "set.h"
using namespace std;

/*
 * parseMessageHelper() takes in a lexicon by reference, and a
 * substring comprising only alpha characters. It implements
 * recursive backtracking to parse all valid words from the
 * substrings.
 *
 * It keeps track of previous valid words in the current pass
 * through original string, and takes in the combination
 * output vector by reference to feed solutions back
 * to the caller function paseMessage().
 */
void parseMessageHelper(Lexicon& lex, string message,
                        string result, Vector<string> &combinations) {
    // base case: all chars have been parsed or emtpy string
    if (message.size() == 0) {
        // trim string padding space delimiters and add to vector
        combinations.add(trim(result));
    }

    // recursive case: for each character in input string
    string word = "";   // initialize starting word string
    int count = 0;      // initialize char count
    for (char ch : message) {
        word += ch;     // add next char in string to word
        count++;        // increment char count
        // check if word is in lexicon
        if (lex.contains(word)) {
            // remove valid word result from left of string and recurse
            parseMessageHelper(lex, message.substr(count),
                               result + " " + word, combinations);
        }
    }
}

/*
 * parseMessage() takes in a lexicon by reference and
 * a string that comprises a continous sequence of valid words
 * using only alpha characters, and returns a string
 * vector containing all combinations of valid words in the
 * original message.
 *
 * The function calls on parseMessageHelper() to accomplish
 * recursive backtracking and string manipulations.
 */
Vector<string> parseMessage(Lexicon& lex, string message) {
    // initialize result vector
    Vector<string> combinations;

    // recursively parse string into valid words
    parseMessageHelper(lex, message, "", combinations);

    return combinations;
}


/* * * * * * Test Code Below This Point * * * * * */

/* Test helper function to return shared copy of Lexicon. Use to
 * avoid (expensive) re-load of word list on each test case.
 *
 * NOTE: Lexicon.h and EnglishWords.txt were used from CS106B
 * Assignment 3 Boggle. I added "im" to the lexicon.
 *
 * Test cases for the lexicon are also used from the starter
 * code from A3.
 */

static Lexicon& sharedLexicon() {
   static Lexicon lex("res/EnglishWords.txt");
   return lex;
}

PROVIDED_TEST("Load shared Lexicon, confirm number of words") {
    Lexicon lex = sharedLexicon();
    EXPECT_EQUAL(lex.size(), 127146);
}

PROVIDED_TEST("Fringe cases: empty string, gobly gook, not all valid words") {
    // initialize variables
    Lexicon lex  = sharedLexicon();
    string empty = {};
    string gook = "g4@!sd#w";
    string notAllValidWords = "helloabc";

    // parse the message
    Vector<string> emptyRes = parseMessage(lex, empty);
    Vector<string> gookRes = parseMessage(lex, gook);
    Vector<string> notValidRes = parseMessage(lex, notAllValidWords);

    // sets must be of the same size
    EXPECT_EQUAL(emptyRes, {""});
    EXPECT_EQUAL(gookRes, {});
    EXPECT_EQUAL(notValidRes, {});
}

PROVIDED_TEST("Test message: appleorchard") {
    // initialize variables
    Lexicon lex  = sharedLexicon();
    string message = "appleorchard";
    Set<string> ss = {
        "apple or chard",
        "apple orchard",
        "apple orc hard"
    };

    // parse the message
    Vector<string> combinations = parseMessage(lex, message);
    Set<string> cs;     // combinations set

    // create a solution set from the combinations
    for (string elem : combinations) {
        cs.add(elem);
    }

    // sets must be of the same size
    EXPECT_EQUAL(cs.size(), ss.size());

    // sets must contain the same elements
    EXPECT(cs == ss);
}

PROVIDED_TEST("Test message: ilikeyoursunglasses") {
    // initialize variables
    Lexicon lex  = sharedLexicon();
    string message = "ilikeyoursunglasses";
    Set<string> ss = {
        "i li key our sun glass es",
        "i li key our sun glasses",
        "i li key our sung lass es",
        "i li key our sung lasses",
        "i li key our sunglass es",
        "i li key our sunglasses",
        "i li key ours un glass es",
        "i li key ours un glasses",
        "i like your sun glass es",
        "i like your sun glasses",
        "i like your sung lass es",
        "i like your sung lasses",
        "i like your sunglass es",
        "i like your sunglasses",
        "i like yours un glass es",
        "i like yours un glasses"
    };

    // parse the message
    Vector<string> combinations = parseMessage(lex, message);
    Set<string> cs;     // combinations set

    // create a solution set from the combinations
    for (string elem : combinations) {
        cs.add(elem);
    }

    // sets must be of the same size
    EXPECT_EQUAL(cs.size(), ss.size());

    // sets must contain the same elements
    EXPECT(cs == ss);
}

PROVIDED_TEST("Test message: impossible") {
    // initialize variables
    Lexicon lex  = sharedLexicon();
    string message = "impossible";

    Set<string> ss = {
        "impossible",
        "im possible"
    };

    // parse the message
    Vector<string> combinations = parseMessage(lex, message);
    Set<string> cs;     // combinations set

    // create a solution set from the combinations
    for (string elem : combinations) {
        cs.add(elem);
    }

    // sets must be of the same size
    EXPECT_EQUAL(cs.size(), ss.size());

    // sets must contain the same elements
    EXPECT(cs == ss);
}
