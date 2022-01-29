Author: Great Canadian Moose
Date: May 13th, 2021
Contact: Hawker on Libera.chat
	(IRC Network)

Introduction to youtube-term:
	youtube-term is a utility that allows a server to monitor a list of youtube channels, and download any new videos. The client FTP
	the server if there are any new videos, and if there is, a transfer will take place.

	The server is a multi-threaded program that is designed for a headless raspbian system, however it should work as long as you have
	access to the g++ compiler, and are able to execute yt-dlp, the heart of this program. https://github.com/yt-dlp/yt-dlp

	The initial version was made early in January before my university classes started, if you want a copy of any older version of
	youtube-term, let me know by talking to me on Libera chat. (https://libera.chat/guides/basics)


How to Use:
	This program is designed to run between two computers, one computer, called the server monitors a list of youtube channels,
	and downloads them for the second computer (likely your PC, called the client), which does not have to monitor the list of youtube channels, saving 
	significant system resources, vital for less powerful computers.

	However if you want, you can run the server program solely on your main computer, however you may see reduced performance.

	The client saves videos to ~/Videos/youtube-term on your PC

	Running these programs, you will likely see SCP errors, or broken pipe errors, that is fine because I have not found a fix for it,
	but they are benign errors that just look ugly, possibly even like yo mamma

Installation Guide:

	On your server computer, create a new directory and in that directory run:
	git clone https://github.com/GreatCanadianMoose/youtube-term

	If you want to edit the number of threads used by your server, open server.cpp and edit the variable in line 6 and save it.

	To set up all the youtube-term files, run
	g++ serverInstaller.cpp -o foo && ./foo


	Lastly, you need to create some SHA keys to SSH into your server from your client machine
	without using a password. Follow the instructions here:
	https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md

	If you SSH into your server, you can use the command:
	nohup ~/youtube-term/v0.x.x/youtube-term
	And then you can close your terminal window with SSH and youtube-term will still run in the background

	Now on your PC, compile the client with:
	g++ client.cpp -o client
	and run it to start periodic checks (every 2 minutes) from the youtube-term server
