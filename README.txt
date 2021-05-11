Author: Luca Salvatore
Date: May 10th, 2021
Contact: youtubeTermProject@email.com

Introduction to youtube-term:
	youtube-term is a utility that allows a server to monitor a list of youtube channels, and download any new videos.
	It is a multi-threaded program that is designed for a headless raspbian system, however it should work as long as you have access
	to a C++ compiler, and are able to execute youtube-dl, the heart of this program.

	The initial version was made early in January before my university classes started, if you want a copy of any older version of
	youtube-term, let me know by emailing me at youtubeTermProject@email.com


Installation Guide:
	There are two parts to youtube-term. The client, which you run on your personal machine; and the server, which you can run on
	a Raspberry Pi, or other suitable Linux machine. The client can be compiled with gcc by running the command:
 g++ client.cpp -o client
	The server needs a couple extra flags to your g++ command, and can properly be compiled with:
 g++ server.cpp -std=c++11 -pthread -o youtube-term
	MAKE SURE YOU COMPILE ON THE SAME COMPUTER YOU RUN FROM TO AVOID ARCHITECTURE ISSUES!!!

	Put all the server files on the server in ~/youtube-term/v0.3.1
	and also please create ~/youtube-term/FTP
	In ~/youtube-term/v0.3.1, please run
 wget https://youtube-dl.org/downloads/latest/youtube-dl
	To download the youtube-dl python script.

	You will have to manually delete the video files that persist in ~/youtube-term/v0.3.1 after FTP.

	Now here's the interesting part, you need to create some SHA keys to SSH into your server from your client machine
	without using a password. Follow the instructions here:
	https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md

	Once your server runs properly, you can run your client, and watch those scp errors scroll across your screen!

	I also reccomend you turn your server on, ssh into your server, and use nohup so you can run the program
	after your SSH tunnel gets closed.

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
