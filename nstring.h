/* * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *           EXPANDED STRINGS FOR C++                *
 *                 BY: IchoTM                        *
 * https://github.com/IchoTM/ExpandedStrings_for_CPP *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#define WIN32_LEAN_AND_MEAN
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class nstring : public string
{
	private:
		vector<char> illegalChars;
		bool isIllegal(char);
	public:
		nstring sheer(int, int);
		nstring sheerUntilDelim(char, int, bool);
		void autoForm();
		void addLaw(char);
		void baseLaw();
		void rmvLaw(char);
		void getLaws() const;
		vector<nstring> divideByDelim(char, bool);
		nstring& operator=(const char[]);
		nstring& operator=(nstring);
		nstring& operator+=(char);
		nstring& operator+=(nstring);
		nstring& operator+(nstring);
		char operator[](int);
		bool operator==(nstring);
		bool operator!=(nstring);
};