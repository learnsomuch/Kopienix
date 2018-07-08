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
    
## Supported Help functions
Here, help function displays list of possible options.
    
    ./uname --help
    ./id --help
    ./ls --help
    ./rm --help

## License
MIT
