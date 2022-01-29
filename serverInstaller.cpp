// Installs the youtube-term utility, and fetches the latest version of yt-dlp
// It doesn't complete the passwordless SSH setup because it requires access on two computers.
// Make make a client install script or something...

#include <iostream>
using namespace std;

int main(){

        cout << "Welcome to the youtube-term setup!\n";

        cout << "Removing pre-existing youtube-term files!" << endl;
        system("rm -rvf ~/youtube-term/v0.3.2");

        cout << "Creating directory tree...\n";
        system("mkdir ~/youtube-term ~/youtube-term/v0.3.2  ~/youtube-term/v0.3.2/FTP ~/youtube-term/v0.3.2/source-code ~/youtube-term/v0.3.2/README");

        cout << "Downloading youtube-dl...\n";
        system("wget github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp");

        cout << "Compiling server code...\n";
        system("g++ server.cpp -std=c++11 -pthread -o youtube-term");

        cout << "Moving files...\n";
        system("mv CHANGELOG.txt ~/youtube-term/v0.3.2/README && mv README.txt ~/youtube-term/v0.3.2/README && mv *.cpp ~/youtube-term/v0.3.2/source-code && mv *.h ~/y$

        cout << "Cleaning up...\n";
        system("rm *");

        cout << "Setup complete! Please make sure you have passwordless SSH access between your client and your server.\n";
        cout << "Follow the guide here: \n";
        cout << "www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md\n";
}


