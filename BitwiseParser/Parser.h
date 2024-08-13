#pragma once
#include <vector>
#include <string>
#include <iostream>

class Bitset {
	std::vector<bool> m_Vecbitset;
	std::string m_strBitset;
	unsigned int m_offset = 0;
public:
	Bitset(std::vector<bool> bitset, int bitsetOffset) : m_Vecbitset(bitset), m_offset(bitsetOffset) {}
	Bitset(std::string strBitset, int bitsetoffset) : m_strBitset(strBitset), m_offset(bitsetoffset) {}
	std::vector<bool> getBitset() { return m_Vecbitset; }
	std::string getStrBitset() { return m_strBitset; }
	int getOffset() { return m_offset; }
};

class Parser {
public:
	template<typename T>
	int getBitsLength(T input) const {
		int counter = 0;
		while (input >= 1) {
			input = input / 2;
			counter++;
		}

		return counter;
	}

	bool is_digits(const std::string& str)
	{
		return str.find_first_not_of("0123456789") == std::string::npos;
	}

	Bitset getBitset(const std::string& input) const
	{
		int content = std::stoi(input);
		int bits = getBitsLength(content);
		int totalBits = 16;
		std::vector<bool> bitset(totalBits);
		int offset = totalBits - bits;
		for (int i = 0; i < totalBits; ++i) {
			bitset[i] = content & (1 << i);
		}

		Bitset currentBitset(bitset, offset);

		return currentBitset;
	}

	Bitset bitsetStr(const std::string& input) const {
		Bitset bitset = getBitset(input);
		std::string temp;

		for (bool bit : bitset.getBitset())
			temp.push_back(bit ? '1' : '0');

		std::reverse(temp.begin(), temp.end());

		Bitset newBitset(temp, bitset.getOffset());

		return newBitset;
	}

	std::string strNOT(Bitset &input) const {
		std::string temp;
		int counter = input.getOffset();

		for (auto c: input.getStrBitset()) {
			if (c == '1' || counter > 0)
				temp += '0';
			else
				temp += '1';

			counter--;
		}	
		return temp;
	}

	std::string strAND(Bitset &input1, Bitset &input2) const {
		std::string temp;

		for (unsigned int i = 0; i < input1.getStrBitset().length(); ++i) {
			if (input1.getStrBitset()[i] == '1' && input2.getStrBitset()[i] == '1')
				temp += '1';
			else
				temp += '0';
		}

		return temp;
	}

	std::string strOR(Bitset& input1, Bitset& input2) const {
		std::string temp;

		for (unsigned int i = 0; i < input1.getStrBitset().length(); ++i) {
			if (input1.getStrBitset()[i] == '0' && input2.getStrBitset()[i] == '0')
				temp += '0';
			else
				temp += '1';
		}

		return temp;
	}
};