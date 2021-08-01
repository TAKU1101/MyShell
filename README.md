# MyShell
like in bash.

## team

- sugita, kamashima

## Description

Implementation of a small shell based on Bash. 

### buildin command

#### echo
with option '-n'
```
$> echo hello
hello
$> echo -n world
world$>
```

#### exit
Set the number in the argument as the exit status
```
$> exit 42
exit
$> echo $?
42
```

#### export
Set environment variables.
```
$> export
... (environment variables list)
$> export A="hello"
$> echo $A
hello
```

#### unset
Remove environment variables
```
$> unset USER
$> echo $USER

$>
```

#### env
Display the list of environment variables
```
$> env
... (environment variables list)
$>
```

#### cd
Change the current directory.
```
$> echo $PWD
/user/tmp
$> cd test
$> echo $PWD
/user/tmp/test
```

### commandline parsing

#### pipe
Redirect the output of the left command to the input of the right command.
```
$> cat hello.txt | cat -e
hello$
world$
!!$
$> 
```

#### semicolon
Splitting the command
```
$> export A="hello"; echo $A; unset $A
hello
```

#### single quotation
Special characters will be escaped.
```
$> echo '＄USER'
$USER
$> echo '\a'
\a
```

#### double quotation
Recognized as a single parameter
```
$> echo "hello            world"
hello            world
```

#### redirection
Redirecting input and output to a file
```
$> ls doesNotFile > log 2> errorLog
$> cat log

$> cat errorLog
ls: doesNotFile: No such file or directory
$> grep ls < errorLog
ls: doesNotFile: No such file or directory
```

### others

#### signal
Corresponding to cntl-D, cntl-C, cntl-\

#### environment variable path
Can be executed at the path set in the PATH environment variable.
