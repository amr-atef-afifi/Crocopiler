/*
 * LRParser.cpp
 *
 *  Created on: Apr 7, 2013
 *      Author: amr
 */

#include "LRParser.h"

LRParser::LRParser() {
	// TODO Auto-generated constructor stub

}

LRParser::~LRParser() {
	// TODO Auto-generated destructor stub
}

bool LRParser::is_definition(string& in) {
	bool is_matched = false;
	regex_t regex;
	int reti;
//	char msgbuf[100];

	/* Compile regular expression */
	reti = regcomp(&regex, "^[a-zA-Z_][a-zA-Z0-9_]*=..*$", 0);
	if (reti) {
		cout << "Could not compile regex" << endl;
		return 0;
	}
	/* Execute regular expression */
	reti = regexec(&regex, in.c_str(), 0, NULL, 0);
	if (!reti) {
//		cout << "Match" << endl;
		is_matched = true;
	} else if (reti == REG_NOMATCH) {
//		cout << "No match" << endl;
		is_matched = false;
	} else {
//		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		cout << "Regex match failed:" << endl;
	}
	/* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regex);
	return is_matched;
}

bool LRParser::is_expression(string& in) {
	bool is_matched = false;
	regex_t regex;
	int reti;
	reti = regcomp(&regex, "^[a-zA-Z_][a-zA-Z0-9_]*:..*$", 0);
	if (reti) {
		cout << "Could not compile regex" << endl;
		return false;
	}
	reti = regexec(&regex, in.c_str(), 0, NULL, 0);
	if (!reti) {
		is_matched = true;
	} else if (reti == REG_NOMATCH) {
		is_matched = false;
	} else {
		cout << "Regex match failed:" << endl;
	}
	regfree(&regex);
	return is_matched;
}

int main() {
	LRParser hero;
	string input = "bgfdh:=jhgyug";
	bool result1 = hero.is_definition(input);
	if (result1) {
		cout << input << "\nis definition" << endl;
	} else {
		bool result2 = hero.is_expression(input);
		if (result2) {
			cout << input << "\nis expression" << endl;
		} else {
			cout << input << "\nnot definition nor expression." << endl;
		}
	}

	return 0;
}

