// Author: Luca Salvatore
// Date May 13th, 2021
//
// This is the client that you should run on your main computer
// You compile it with:
// g++ client.cpp -o youtube-term-client
// and run it in place with:
// ./client

#include <iostream>
#include <string>

using namespace std;

int main(){

	// Initialize string to store the location of the server
	string IP;

	// Friendly little prompt
	cout << "What hostname and IP address is the server located at?\n\t--> ";
	cin >> IP;
	cout << endl;

	// Initialize the commands
	string rmCMD = "ssh " + IP + " 'rm ~/youtube-term/FTP/*'";
	string scpCMD = "scp " + IP + ":~/youtube-term/FTP/* ~/Videos/youtube-term";
	system("mkdir ~/Videos/youtube-term");
	while(true){ // Litterally run the commands forever
		system(scpCMD.c_str());
		system(rmCMD.c_str());
		system("sleep 180");
	}
	return 69; // This return should never be called... only interupts
}
