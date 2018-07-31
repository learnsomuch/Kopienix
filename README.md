# Kopienix
Implementation of linux commands to learn C


# Build Script
Once you get the repository, execute the build file to generate bin folder with executable commands.


## Execution of indiviual commands from src directory
gcc <command.c> -o \<command>

eg. 

    gcc date.c -o ../bin/date

## Current list of commands inside bin directory
    ./date
    ./uname
    ./pwd
    ./whoami
    ./id
    ./dir
    ./ls
    ./rm <filename>
    ./cat <filename>
    ./hostname
    ./nslookup <web address>
    ./uptime
    ./who
    ./w
    ./free
    ./sleep <seconds>
    ./mv <source file> <target location with file name>
    
    
## Supported Help functions
Here, help function displays list of possible options.
    
    ./uname --help
    ./id --help
    ./ls --help
    ./rm --help
    ./nslookup --help
    ./cat --help
    ./free --help
    ./mv --help
    ./sleep --help

## License
MIT 2018
