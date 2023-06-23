

///* #########################################################
// * Personal Project: Parsing a message
// * Work by Nikolas Weissmueller (@nweissm)
// * Class: CS 106B, Summer Term, August 2022
// *
// * This cpp file provides functionality to recursively parse
// * a continuous string, constructed entirely of alphabet
// * lower case characters, and without space delimeters,
// * into all possibe combinations of valid words.
// *
// * Solution 3: Recursive backtracking and pass by value.
// *
// * Functionality test cases are provided.
// *
// * #########################################################
// */

//#include <iostream>
//#include "testing/SimpleTest.h"
//#include "testing/TextUtils.h"
//#include "strlib.h"
//#include "vector.h"
//#include <string>
//#include "lexicon.h"
//#include "set.h"
//using namespace std;

//Vector<string> parseMessageHelper2(Lexicon& lex, string str,
//                                   string result, Vector<string> combinations) {
//    // base case: all chars have been parsed or emtpy string
//    if (str.size() == 0) {
//        combinations.add(result);
//    }
//    // recursive case: for each character in input string
//    string word = "";   // initialize starting word string
//    int count = 0;      // initialize char count
//    for (char ch : str) {
//        word += ch;     // add next char in string to word
//        count++;        // increment char count
//        // check if word is in lexicon
//        if (lex.contains(word)) {
//            // chop off valid word result from string and recurse on the remaining substring
//            combinations = parseMessageHelper2(lex, str.substr(count),
//                                               result + word + " ", combinations);
//        }
//    }
//    return combinations;
//}

//// Prints all possible word breaks of given string
//Vector<string> parseMessage2(Lexicon& lex, string str) {
//    // initialize result vector
//    Vector<string> combinations;

//    // recursively parse string into valid words
//    combinations = parseMessageHelper2(lex, str, "", combinations);

//    return combinations;
//}
//// Prints all possible word breaks of given string
////void parseString(Lexicon& lex, string str, int n, string result, Vector<string> &combinations) {
////    // for all starting locations
////    for (int i = 0; i <= n; i++) {
////        // Extract substring from 0 to i in prefix
////        string word = str.substr(0, i);
////        if (lex.contains(word)) {
////            // recursive case: parse remaining substring
////            parseWordHelper(lex, str.substr(i, n-i), n-i, result + word + " ", combinations);
////            // base case: add words to final result
////            if (n - i == 0){
////                result += word;
////                combinations.add(result);
////            }
////        }
////    }
////}

///* * * * * * Test Cases * * * * * */
///* Test helper function to return shared copy of Lexicon. Use to
// * avoid (expensive) re-load of word list on each test case. */
//static Lexicon& sharedLexicon() {
//   static Lexicon lex("res/EnglishWords.txt");
////   static Lexicon lex("res/SpanishWords.txt");
//    return lex;
//}

////PROVIDED_TEST("Load shared Lexicon, confirm number of words") {
////    Lexicon lex = sharedLexicon();
////    EXPECT_EQUAL(lex.size(), 127145);
////}

////PROVIDED_TEST("Load shared Lexicon, confirm number of words") {
////    Lexicon lex = sharedLexicon();
////    string test = "sun";
////    EXPECT(lex.contains(test));
////}

//PROVIDED_TEST("Test strings: must be parsable into individual valid words") {
//    Lexicon lex  = sharedLexicon();
//    Vector<string> combinations;

//    string input = "tangerine";
//    parseMessage2(lex, input);

//    input = "sunglasses";
//    parseMessage2(lex, input);

//    input = "appleorchard";
//    combinations = parseMessage2(lex, input);

//    // print out all elements in the string vector
//    for (string elem : combinations) {
//        cout << elem << endl;
//    }

//    input = "";
//    parseMessage2(lex, input);

//    input = "abcdefgh";
//    parseMessage2(lex, input);

//    input = "appleabc";
//    parseMessage2(lex, input);

//    input = "abcapple";
//    parseMessage2(lex, input);

//    input = "carrot";
//    parseMessage2(lex, input);

//    input = "onomatopoeia";
//    parseMessage2(lex, input);

//    input = "ababillaba";
//    parseMessage2(lex, input);

//    input = "helloworld";
//    parseMessage2(lex, input);

//    input = "whatdoyouthink";
//    combinations = parseMessage2(lex, input);
//    // print out all elements in the string vector
//    for (string elem : combinations) {
//        cout << elem << endl;
//    }

//    input = "";
//    parseMessage2(lex, input);
//}

////PROVIDED_TEST("Test strings") {
////    Lexicon lex  = sharedLexicon();
////    string input = "sunglasses";
////    parseWord(lex, input);
////}

////PROVIDED_TEST("Test strings") {
////    Lexicon lex  = sharedLexicon();
////    string input = "appleorchard";
////    parseWord(lex, input);
////}
///
/// // FROM solution 1
//void parseMessageHelper(Lexicon& lex, string message,
//                        string result, Vector<string> &combinations) {
//    // base case: all chars have been parsed or emtpy string
//    if (message.size() == 0) {
//        // trim string padding space delimiters and add to vector
//        combinations.add(trim(result));
//    }

//    // recursive case: for each character in input string
//    string word = "";   // initialize starting word string
//    for (int i = 1; i <= message.size(); i++) {
//        word = message.substr(0, i);     // add next char in string to word
//        // check if word is in lexicon
//        if (lex.contains(word)) {
//            // remove valid word result from left of string and recurse
//            parseMessageHelper(lex, message.substr(i),
//                               result + " " + word, combinations);
//        }
//    }
//}

//Vector<string> parseMessageHelper3(Lexicon& lex, string message, int n,
//                                    string result, Vector<string> combinations) {
//    // recursive case: for each character in input string
//    string word = "";   // initialize starting word string

//    for (int i = 0; i <= n; i++) {
//        // parse substring from 0 to i
//        string word = message.substr(0, i);
//        if (lex.contains(word)) {
//            // recursive case remove valid word result from left of string and recurse
//            combinations = parseMessageHelper3(lex, message.substr(i, n-i), n-i,
//                                               result + " " + word , combinations);
//        }
//        // base case: all chars have been parsed or emtpy string
//        if (n == 0) {
//            combinations.add(trim(result));
//        }
//    }
//    return combinations;
//}
