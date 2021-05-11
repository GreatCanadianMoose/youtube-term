// This is an alternitive to the system() command, where instead
// This function actually outputs a string which is useful for
// interpreting the terminal output

// The following code is made by "Abhinanda Shri"
// Modified from:
// https://www.tutorialspoint.com/How-to-execute-a-command-and-get-the-output-of-command-within-Cplusplus-using-POSIX
// August 13, 2020

string exec(string command) {
   char buffer[128];
   string result = "";

   cout << "In command!\t";
   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      cout << "Life is sad" << endl;
   }

   cout << "Pipe opened, reading process\t";
   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
        if (fgets(buffer, 128, pipe) != NULL)
              result += buffer;

        }

        pclose(pipe);
        cout << "pipe closed, command shutting down\n";
        return buffer;
}

