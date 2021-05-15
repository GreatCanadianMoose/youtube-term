// Installs the youtube-term utility, and fetches the latest version of youtube-dl
// It doesn't complete the passwordless SSH setup because it requires access on two computers.
// Make make a client install script or something...

#include <iostream>
using namespace std;

int main(){

	cout << "Welcome to the youtube-term setup!\n";

	cout << "Creating directory tree...\n";
	system("mkdir ~/youtube-term ~/youtube-term/FTP ~/youtube-term/source-code ~/youtube-term/README");

	cout << "Downloading youtube-dl...\n";
	system("wget youtube-dl.org/downloads/latest/youtube-dl");

	cout << "Compiling server code...";
	system("g++ server.cpp -std=c++11 -pthread -o youtube-term");

	cout << "Moving files...";
	system("mv CHANGELOG.txt ~/youtube-term/README && mv README.txt ~/youtube-term/README && mv *.cpp ~/youtube-term/source-code && mv *.h ~/youtube-term/source-code && mv y* ~/youtube-term");

	cout << "Cleaning up...";
	system("rm * && rmdir ../v0.3.2");

	cout << "Setup complete! Please make sure you have passwordless SSH access between your client and your server.\n";
	cout << "Follow the guide here: \n";
	cout << "www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md";
}
