// Author:  Luca Salvatore
// Date:    May 21st, 2021
// Purpose: Downloads youtube videos given a list of channels to download from
// g++ -std=c++11 -pthread is required to compile
// Number of threads to use:
int numThreads = 4;

// Required includes
#include <chrono>
#include <stdio.h>
#include <thread>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <typeinfo>
#include "LinkedList.h"
#include "exec.h"
#include "downloadCheck.h"

using namespace std;

void downloadCheck(string channel); // Function declaration
string exec(string command);

int main(){

	if(numThreads <= 0){
		cout << "Bro, what the heck? You're supposed to have at least 1 thread to run this program. Please recompile server.cpp\n\n\n";
		return 1;
	}

	thread thr[numThreads];

	time_t start;
	time_t finish;

	int n = 1;		// Loop variable to keep track of the number of time this runs
	LinkedList manipList; 	// This is the linked list that I use to access the ytsubs.txt periodically
	while(n > -1){ 		// Forever do inside the loop.



		time(&start);

		ifstream subList("ytsubs.txt"); // open the ytsubs.txt file to read channel links from

		string channel;

		while(getline(subList, channel)){ // For each line in ytsubs, take one line and add it to the linked list.
			manipList.insertHead(channel);
		}

		subList.close(); // close sublist file don't want bad things to happen to it

		int modulusLoop = 0;

		if(numThreads > 1){
			while(modulusLoop <= manipList.size() % numThreads){ 	// To keep the program from running into a segmentation fault, the modulus MUST
				downloadCheck(manipList.getAt(0)); 		// be of the same number of threads you run
				manipList.deleteHead();		   		// I will add a variable at the top of the program that automatically handles the
				modulusLoop ++;			    		// multithreading so you don't have to edit this section.
			}
		}
		while(manipList.head != nullptr){			// I run 4 cores because I have a Raspberry Pi 3 B which is what I use
// This is the multi-threading section
// I will do my Windows testing on a 2004 XP machine with one core at 2.5GHz (If memory serves)
// with 1GB of DDR2 RAM. However I intend it to run on a much lower spec machine
// I may talk later to someone to figure out how to improve my code for low-spec PCs
// Pretty much any main line raspberry pi since the Pi 2 has 4 cores... even the 3A+

			for(int i = 0; i < numThreads; i++){
				thr[i] = thread(downloadCheck, manipList.getAt(0));
				manipList.deleteHead();
			}


			for(int i = 0; i < numThreads; i++){
				thr[i].join();
			}


			// This last section logs tempature by running the cat command on the file, then saving it to tempature.txt
			// This allows a sysadmin to keep an eye on tempatures over time in case there may be a thermal issue
			string tmp("tempature.txt"); // Open temp log file
			ofstream file_out;

			file_out.open(tmp, std::ios_base::app); // Append to the end
			file_out << exec("cat /sys/class/thermal/thermal_zone0/temp") << endl;

			file_out.close(); // Close temp log file
		}

			time(&finish);
			string rum = "find . -maxdepth 1 -cmin "+ to_string((int)(difftime(start,finish)/60) - 2) + " -type f ! -name '*.txt' ! -name '*.cpp' ! -name '*.h'  ! -name 'youtube-dl' ! -name 'youtube-term' -print0 | xargs -0 cp -t ~/youtube-term/v0.3.2/FTP";
//                        string rum =  "find . -cmin -" + to_string(difftime(start,finish)/60 + 1) + " -maxdepth 1 -type f ! -name '*.txt' ! -name '*.cpp' -name '*.h' ! -name 'youtube-dl' ! -name 'youtube-term' -print0 | xargs -0 cp -t ~/youtube-term/v0.3.2/FTP";

                        exec(rum);
			exec("find . -mmin +1440 -type f ! -name '*.txt' ! -name '*.cpp' -name '*.h' ! -name 'youtube-dl' ! -name 'youtube-term' -delete");

	}
	return 0;
}
