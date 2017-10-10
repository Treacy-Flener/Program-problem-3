#include "stdafx.h"
#include "TextToSpeech.h"
#include "SongDB.h"

using namespace std;
bool fast = false;
void UpSet() {
	int xSize = 16;
	for (int i = 0; i < (xSize); i++) {
		TTS(NationAnthem[i]);
		for(int k = 0; k < 9; k++)
			if (i == k){}
	}
}

string trim(string str) {
	int beg_str, end_str;
	beg_str = 0;
	end_str = str.length() - 1;
	for(int i = 0;beg_str == 0 && i < str.length(); i++)
		if (str[i] != ' ') {
			beg_str = i;
			i += str.length() + 5;
		}
	for(int i = end_str; (beg_str != 0) && (end_str == str.length()-1) && (i > beg_str); i--)
		if (str[i] != ' ') {
			end_str = i;
			i = beg_str - str.length() - 5;
		}
	//cout << beg_str << ":"<< end_str << "*"<< str.substr(beg_str, end_str) << "* ";
	return str.substr(beg_str, end_str);
}

void TTS(string SentMessage) {
	if (SentMessage == "SUNA") {
		UpSet();
		return;
	}
	int argc = 3;
	wchar_t* LANG = L"SAM";

	wchar_t* Message = L"This is Microsoft Alice, Welcome to Computer Science One. Good Morning!";
	//while (SentMessage[0] == ' ' && SentMessage.length() > 0)
		//SentMessage = SentMessage.substr(1);	
	if(fast)
	if (SentMessage.find(' ') > 0 && SentMessage.find(' ') < SentMessage.length()) {
		SentMessage = trim(SentMessage);
		string place = trim(SentMessage.substr(0, SentMessage.find(' ')+1));
		TTS(place);
		cout << place << endl;
		place = "";
		int k = SentMessage.find(' ');
		for( ; k < SentMessage.length(); k++)
				if (SentMessage[k] != ' ')
				{
					place = SentMessage.substr(k);
					k += SentMessage.length() + 2;
				}
		//cout << place << '/n';
		if (place != "")
			TTS(place);
		return;
	}
	string storeMessage = SentMessage;
	wchar_t* conversion = new wchar_t[storeMessage.length() + 1];
	copy(storeMessage.begin(), storeMessage.end(), conversion);
	conversion[storeMessage.length()] = 0;

	if (FAILED(::CoInitialize(NULL)))
		return;

	if (argc == 3) {
		try {
			wchar_t * voice = getLanguage(LANG);
			bool spoken = speak(conversion, voice);
		}
		catch (wchar_t* ex) {
			wcout << "ERROR " << ex << endl;
		}
	}
	else {
		wcout << "ERROR " << " You made a mistake in arguments." << endl;
	}

	::CoUninitialize();
	//system("pause");
}