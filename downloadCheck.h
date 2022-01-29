// Modified exec.h to suit my needs

void downloadCheck(string channel){

	string lengthTime;

	time_t dt = time(0); // Date structure to be used in the youtube-dl command
	tm *Date = localtime(&dt);
	int year = 1900 + Date->tm_year; // Get the year and put it in the year variable
	int month = 1 + Date->tm_mon; // Rinse and repeat with month & day
	int day = Date->tm_mday;

	string strMonth; // Initialize even MORE strings, used to manipulate month/date into a proper format
	string strDay;

	if(month < 10){ 				// So this part is about formatting
		strMonth = "0" + to_string(month);	// We can't pass in 3 for the month in the youtube-dl command
	}else{ strMonth = to_string(month);} 		// Instead 03 needs to be passed in

	if(day < 10){ 					// So if the raw date number is less than 10, prepend the string with a zero
			strDay = "0" + to_string(day);  // The year is fine, no issues there
	}else{ strDay = to_string(day);}

	string prt1 = "python3 yt-dlp --date " + to_string(year) + strMonth + strDay + " "; // This is the first part of the command

	string command = prt1 + channel; // This next bit just converts string to a char... I am not comfortable with them at this point

	cout << command << endl; // This part is a modified exec command, however with one key difference
	char buffer[128];
	string result = "";
	FILE* pipe = popen(command.c_str(), "r"); // Open pipe to file
	if (!pipe) {
		cout << "popen failed!\n";
	}
	// read till end of process:
	while (!feof(pipe)) {
	// use buffer to read and add to result
      		if (fgets(buffer, 128, pipe) != NULL){result += buffer;}
			size_t found = result.find("upload date is not in range"); // If it sees this string, it aborts the command, breaking
			if(found != string::npos){break;}			   // the pipe and exiting
		}								   // This prevents youtube-dl from trying to download videos
	pclose(pipe);								   // that are outside of the current date, because it has to
										   // download each video's webpage in order to figure out
										   // that it can't download it, for youtube channels with
										   // hundreds or even thousands of videos, this is a huge
										   // issue.
	this_thread::sleep_for(std::chrono::milliseconds(1)); // Sleep for a touch for everything to settle just incase
}
