//#pragma once
#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "strlib.h"
#include "vector.h"
#include <string>
#include "lexicon.h"

using namespace std;

// Prototypes to be shared with other modules
Vector<string> parseMessage2(Lexicon& lex, string str);

Vector<string> parseMessageHelper2(Lexicon& lex, string str, string result, Vector<string> combinations);
