#!/bin/bash
src=$1
executable=$2
g++ -std=c++11 -Wall -Wextra -O2 -D KUSH_LOCAL $src -o $executable
command="$executable;read -p '[Press enter]';exit"
/usr/bin/osascript << EOF
	set cmd to "$command"
	if application "Terminal" is running then
		tell application "Terminal"
			activate
			do script cmd
		end tell
	else
		tell application "Terminal"
			activate
			do script cmd in window 1
		end tell
	end if
EOF

#/usr/bin/osascript -e 'do shell script ""'