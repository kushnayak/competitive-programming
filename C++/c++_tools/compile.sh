#!/bin/bash
src=$1
executable=$2 
g++ -std=c++11 -Wall -Wextra -O2 -D KUSH_LOCAL $src -o $executable
if [ -s "$3" ]; then #if there is an input text and it is not empty
	command="$executable<$3;read -p '[Press enter]';exit;"
else 
	command="$executable;read -p '[Press enter]';exit;"
fi
/usr/bin/osascript << EOF
	set cmd to "$command"
	tell application "Terminal"
		if application "Terminal" is running then
			tell application "System Events" to tell process "Terminal"
				click menu item "New Window" of menu "Shell" of menu bar 1
			end tell
			do script cmd in window 1
		else
			activate
			do script cmd in front window
		end if
	end tell
	activate 
EOF


#/usr/bin/osascript -e 'do shell script ""'
	# set cmd to "$command"
	# if application "Terminal" is running then
	# 	tell application "Terminal"
	# 		activate
	# 		do script cmd
	# 	end tell
	# else
	# 	tell application "Terminal"
	# 		activate
	# 		do script cmd in window 1
	# 	end tell
	# end if