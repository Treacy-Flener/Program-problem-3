// ConsoleApplication1.cpp : Defines the entry point for the console application.
// This Library is from GitHub 

#include "stdafx.h"
#include "speak.h"
#include "language.h"
#include "targetver.h"
#include "TextToSpeech.h"
using namespace std;
const int pause_beforeRead = 110;
const int pause_afterRead = 150;



int wmain()
{

	string collect;
	int number_of_classes;

	//TTS("Text to Speech Program version one point one.");
	TTS("Hello my name is Lauren");
	if (false) {
		TTS("How many classes are you taking?");
		cin >> number_of_classes;

		collect = "You are currently taking " + to_string(number_of_classes) + " classes this year.";
		TTS(collect);
		int number_of_members;
		TTS("how many people are in your family?");
		cin >> number_of_members;
		collect = "you have" + to_string(number_of_members) + "in your family";
		TTS(collect);

		char first_letter_of_last_name;
		TTS("What is the first letter of your last name?");
		cin >> first_letter_of_last_name;
		collect = "Your last name starts with" + to_string(first_letter_of_last_name);

		TTS(collect);

		int classgrade;
		TTS("What is your grade in english? Inter it as a whole number");
		cin >> classgrade;
		collect = "Your grade in English is a" + to_string(classgrade);
		TTS(collect);
	}
	// part 2

	int three_digit_number;
	int value_1;
	int value_2;
	int value_3;
	TTS("Enter a three digit number ");
	cin >> three_digit_number;
	value_1 = three_digit_number / 100;
	value_2 = (three_digit_number / 10) % 10;
	value_3 = three_digit_number % 10;
	collect = "Your three digit number was " + to_string(three_digit_number) + " its first digit was " + to_string(value_1) + " its second digit was " + to_string(value_2) + " and its last digit was " + to_string(value_3);
	TTS(collect);
	if (value_1 > value_2 && value_2 > value_3)
	{
		TTS("the number is desending");
	} 
	else if (value_1 < value_2 && value_2 < value_3)
	{
		TTS("The numbers are assending");
	}
	else {
		TTS("The numbers are neither assending or decending");
	}
	
}