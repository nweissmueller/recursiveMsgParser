//#pragma once

#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "strlib.h"
#include "vector.h"
#include <string>
#include "lexicon.h"
#include "set.h"

using namespace std;

// Prototypes to be shared with other modules
Vector<string> parseMessage(Lexicon& lex, string message);

void parseMessageHelper(Lexicon& lex, string message, string result, Vector<string> &combinations);





