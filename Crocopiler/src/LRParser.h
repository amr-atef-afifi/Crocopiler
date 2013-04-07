/*
 * LRParser.h
 *
 *  Created on: Apr 7, 2013
 *      Author: amr
 */

#ifndef LRPARSER_H_
#define LRPARSER_H_
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
using namespace std;

class LRParser {
public:
	LRParser();
	virtual ~LRParser();
	bool is_definition(string&);
	bool is_expression(string&);
};

#endif /* LRPARSER_H_ */
