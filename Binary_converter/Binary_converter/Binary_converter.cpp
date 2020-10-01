// Binary_converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include "Converter_table.h"
using namespace std;

static string bin_str;
static string input;
static char inp;
static enum type {
	ASCII_TO_BIN,
	BIN_TO_ASCII,
	ASCII_TO_HEX,
	HEX_TO_ASCII,
	HEX_TO_BIN,
	BIN_TO_HEX,
	DEBUG,
	UNDEFINED
};

static type conv = UNDEFINED;

static void bintoAsc(string inp) {
	string leng = "";	
	string finall = "";
	int count = 1;

	for (int i = 0; i < input.length() + 1; i++) {	

		if (leng.length() < 8) {
			leng = leng + input[i];			
		}
		else if (leng.length() == 8) {
			cout << leng << " -> " << Convert::BIN_TO_ASCII(leng) << endl;
			finall = finall + Convert::BIN_TO_ASCII(leng);
			leng = input[i];
		}		
	};
	
	cout << endl << "Result:" << endl << finall << endl;

	cout << endl << endl;	
}


static void asciitoBin() {

	for (int i = 0; i < input.length(); i++) {		
		cout << input[i] << " -> " << Convert::ASCII_TO_BIN(input[i]) << endl;
	};

	cout << endl << "Result:" << endl;

	for (int i = 0; i < input.length(); i++) {			
		cout << Convert::ASCII_TO_BIN(input[i]);
	};

	cout << endl << endl;
}


static void bintoHex() {
	string leng = "";
	string finall = "";
	int count = 1;

	for (int i = 0; i < input.length() + 1; i++) {

		if (leng.length() < 4) {
			leng = leng + input[i];
		}
		else if (leng.length() == 4) {
			cout << leng << " -> " << Convert::BINARY_TO_HEX(leng) << endl;
			
			if (count == 2) {
				finall = finall + Convert::BINARY_TO_HEX(leng) + ' ';
				count = 1;
			}
			else {
				finall = finall + Convert::BINARY_TO_HEX(leng);
				count++;
			}
			leng = input[i];
		}
	};

	cout << endl << "Result:" << endl << finall << endl;

	cout << endl << endl;
}


static void hextoBin() {
	for (int i = 0; i < input.length(); i++) {
		cout << input[i] << " -> " << Convert::HEX_TO_BINARY(input[i]) << endl;
	};

	cout << endl << "Result:" << endl;

	for (int i = 0; i < input.length(); i++) {
		cout << Convert::HEX_TO_BINARY(input[i]);
	};

	cout << endl << endl;
}

static void asciitoHex() {	
	string res = "";
	
	for (int i = 0; i < input.length(); i++) {	
		cout << input[i] << " -> " << Convert::ASCII_TO_BIN(input[i]) << endl;
		res = res + Convert::ASCII_TO_BIN(input[i]);		
	};	
	input = res;
	bintoHex();	
}

static void hextoAscii() {	
	string res = "";
	for (int i = 0; i < input.length(); i++) {		
		cout << input[i] << " -> " << Convert::HEX_TO_BINARY(input[i]) << endl;
		res = res + Convert::HEX_TO_BINARY(input[i]);		
	};
	input = res;	
	bintoAsc(res);	
}

static void prompt() {
	cout << "What would you like to convert?" << endl;
	input = "";
	getline(cin, input);

	system("cls");	

	cout << "Converting: " << input << endl;

	switch (conv) {

	case ASCII_TO_BIN:
		asciitoBin();
		break;

	case BIN_TO_ASCII:
		bintoAsc(input);
		break;

	case ASCII_TO_HEX:
		asciitoHex();
		break;

	case HEX_TO_ASCII:
		hextoAscii();
		break;

	case HEX_TO_BIN:
		hextoBin();
		break;

	case BIN_TO_HEX:
		bintoHex();
		break;

	case DEBUG:
		cout << input << endl;
		return;

	default:
		return;
	}	
}

static void decide() {	
	cout << "What would you like to do?" << endl << "binary to ascii" << endl << "ascii to binary" << endl
		<< "ascii to hex" << endl << "hex to ascii" << endl << "binary to hex" << endl << "hex to binary" << endl
		<< "############################################" << endl;
	string inn;
	getline(cin, inn);
	system("cls");
	if (inn == "ascii to binary") {
		conv = ASCII_TO_BIN;
	}
	else if (inn == "binary to ascii") {
		conv = BIN_TO_ASCII;
	}
	else if (inn == "ascii to hex") {
		conv = ASCII_TO_HEX;
	}

	else if (inn == "hex to ascii") {
		conv = HEX_TO_ASCII;
	}

	else if (inn == "hex to binary") {
		conv = HEX_TO_BIN;
	}

	else if (inn == "binary to hex") {
		conv = BIN_TO_HEX;
	}

	else if (inn == "debug") {
		conv = DEBUG;
	}
	else { 
		system("cls");
		cout << "Invalid Option..." << endl;
		Sleep(1500);
		system("cls");
		decide(); 
	};

	prompt();
	decide();
}

int main()
{
	decide();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu