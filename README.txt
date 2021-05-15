Author: Luca Salvatore
Date: May 13th, 2021
Contact: youtubeTermProject@email.com

Introduction to youtube-term:
	youtube-term is a utility that allows a server to monitor a list of youtube channels, and download any new videos. The client will
	ask the server if there are any new videos, and if there is, a transfer will take place.

	The server is a multi-threaded program that is designed for a headless raspbian system, however it should work as long as you have
	access to the g++ compiler, and are able to execute youtube-dl, the heart of this program.

	The initial version was made early in January before my university classes started, if you want a copy of any older version of
	youtube-term, let me know by emailing me at youtubeTermProject@email.com


How to Use:
	This program is designed to run between two computers, one computer, called the server monitors a list of youtube channels,
	and downloads them for the second computer (likely your PC, called the client), which does not have to monitor the list of youtube channels, saving significant
	system resources, vital for less powerful computers.

	However if you want, you can run the server program solely on your main computer, however you may see reduced performance.

	The client saves videos to ~/Videos/youtube-term on your PC

	Running these programs, you will likely see SCP errors, or broken pipe errors, that is fine because I have not found a fix for it,
	but they are benign errors that just look ugly.

Installation Guide:

	On your server computer, create a new directory and in that directory run:
	git clone https://github.com/GreatCanadianMoose/youtube-term

	If you want to edit the number of threads used by your server, open server.cpp and edit the variable in line 6 and save it.

	To set up all the youtube-term files, run
	g++ serverInstall.cpp -o foo && ./foo


	Lastly, you need to create some SHA keys to SSH into your server from your client machine
	without using a password. Follow the instructions here:
	https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md

	If you SSH into your server, you can use the command:
	nohup ~/youtube-term/youtube-term
	And then you can close your terminal window with SSH and youtube-term will still run in the background

	Now on your PC, compile the client with:
	g++ client.cpp -o client
	and run it to start periodic checks (every 2 minutes) from the youtube-term server

Last remarks:
	I genuinely thank you for reading through all this and your interest in my project. I hope you check out youtube-dl's project
	at youtube-dl.org, and occasionally update youtube-dl if it stops working. I will confess, this is my first project that I am
	comfortable publically releasing. Because I am not used to git, and its utilities, I may be slow to update/monitor push/pull
	requests. (Yes, that's how unfamiliar with git I am!) However I will order a book from the library and will read up on it.

Donations:
	You probably shouldn't donate to me simply because I will stop maintaining it sporadically, and come back a couple months later,
	due to my university schedule, and any updates I make are completely up to me and will likely focus on making it run on old machines.

Bitcoin: 1G9fG1fkdvq5HFtU3a2YknCyT5RFByApxJ
Etherium: 0xbE6fCC5f9c690296fF925787fBc657665672be05
Monero: 48hkL8oa6wGbqN8xGwkNHJiudBsLPxaAzC7SUUseNxDmRWFgHwXbenMJG5YffXFc6NgL2ynqVjht25kw5pWDoRHv8fM7t2L
Dogecoin: DGB6AVW78xv4tKzjwkPoPVc7xh6SsEUu8h
