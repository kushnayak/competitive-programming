
#!/bin/bash

src=$1
executable=$2 
dir=$(dirname "$0") # $0 returns the location of this script, dirname just chops the file off to create directory

g++-10 -std=c++11 -Wall -Wextra -O2 -Wl,-stack_size -Wl,0x10000000 -D KUSH_LOCAL $src -o $executable
# prevent stack overflow: use "-Wl,-stack_size -Wl,0x10000000" to incraease stack size from 8 mb to 256 mb
# remove -Werror if you do not want "warnings" from -Wall,-Wextra, etc. to be treated
# as errors which will result in return value of code with warnings with not 0

if [ $? -ne 0 ]; then  # if the return of the last command (g++) returns not 0 (failed compilation or warning [see above]) 
	exit 1
fi

if [ -s "$3" ]; then # if there is an input text and it is not empty
	echo "Input from $3"
	exec="$executable<$3" 
else 
	exec="$executable"  
fi

# -rsn1 to press any key to continue https://www.tweaking4all.com/software/linux-software/bash-press-any-key/
command="$exec;echo''; read -p'Press enter to continue . . .';exit"

# alias and source the run command to make the output in the new terminal window less cluttered 
# when the command is called and echoed 
alias_run="run_$(basename $1)"
echo "alias $alias_run=\"$command\"" >> ~/competitive-programming/C++/tools/command.sh
source ~/competitive-programming/C++/tools/command.sh

/usr/bin/osascript << EOF
	set out to "$alias_run"
	tell application "Terminal"
		if application "Terminal" is running then
			tell application "System Events" to tell process "Terminal"
				click menu item "New Window" of menu "Shell" of menu bar 1
			end tell
			do script out in window 1
		else
			activate
			do script out in front window
		end if
	end tell
	activate 
EOF

#cat /dev/null > ~/competitive-programming/C++/tools/command.sh
echo "#Dummy file to source alias for running executable" > ~/competitive-programming/C++/tools/command.sh