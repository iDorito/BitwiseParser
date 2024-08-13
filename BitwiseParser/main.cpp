#include <iostream>
#include "Parser.h"

int main() {

	Parser parser;
	Bitset input(parser.bitsetStr("123"));
	Bitset input2(parser.bitsetStr("456"));
	
	std::cout << "My parser: " << input.getStrBitset() << std::endl;
	std::cout << "My parser: " << input2.getStrBitset() << std::endl << std::endl;
	std::cout << "NOT opera: " << parser.strNOT(input) << std::endl;
	std::cout << "AND opera: " << parser.strAND(input, input2) << std::endl;
	std::cout << "OR  opera: " << parser.strOR(input, input2) << std::endl;

	return 0;
}