# Kopienix
Implementation of linux commands to learn C




## Execution of indiviual commands from src directory
gcc <command.c> -o \<command>

eg. 

    gcc date.c -o ../bin/date
    gcc uname.c -o ../bin/uname
    gcc pwd.c -o ../bin/pwd
    gcc whoami.c -o ../bin/whoami
    gcc id.c -o ../bin/id
    gcc dir.c -o ../bin/id
    gcc ls.c -o ../bin/ls


## Current list of commands inside bin directory
    ./date
    ./uname
    ./pwd
    ./whoami
    ./id
    ./dir
    ./ls
    
## Supported Help functions
Here, help function displays list of possible options.
    
    ./uname --help
    ./id --help
    ./ls --help

## License
MIT
