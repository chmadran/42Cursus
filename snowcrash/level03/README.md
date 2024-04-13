<h1>LEVEL03</h1>


<h4>GETTING STARTED</h4>

Upon launching this level, you'll notice an executable named `level03` in the home. When launching it, it simply prints `Exploit me` in the console. If you `ls -la` here, you'll notice the permissions have an `s` in it : `-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03`.


<h4>SET UID</h4>

Normally, when a process on a Linux system is started it runs using the uid/gid of whatever user called it. This means it has the same privileges as the associated uid/gid would have. If neither your user, nor any of your real or effective groups have access, neither will you.

A file with an `s` permission means there's a setuid - set user id upon execution - activated. It means that the file when launched will be executed with the setuid's user's permissions instead of the ones of the user who launches it. It is a bit that makes an executable run with the privileges of the owner of the file.

The perfect example is changing one's password. To do so, you must write in `/etc/shadow`. While only root can do that, you can still change your password, why ? Because these are `/etc/passwd`'s persmissions : 

```-rwsr-xr-x 1 root root 68208 May 28 01:37 /bin/passwd```

Because the setuid bit is set, when we run the passwd command it is automatically executed as the owner of the file. Since root is the owner, the password changes and an edit to `/etc/shadow work` is required.


<h4>/USR/BIN/ENV</h4>

Using the `strings` command searches the given files for sequences of printable characters and displays them. This can be particularly handy for several purposes, such as analyzing binary executables to find human-readable content without needing to execute them, debugging, or even for forensic analysis in security-related tasks. When `strings ./level03` : we find `/usr/bin/env echo Exploit me`.

So we notice here there's a file launched with `flag03`'s permissions that makes a call to the echo executable. First, identify the current path of the command's executable you want to replace. You can use the which command for this: `which echo -> /bin/echo`.  

Then, in a file where you have write permissions like`/tmp` create a file `/echo` in which is written `echo getflag` then replace the path of `echo` with `/tmp/`. To do so add to PATH using `export PATH=/tmp:$PATH`. 

You can also use the command `cp` to copy the executable `cp /bin/getflag /tmp/echo`. Don't forget to chmod 777 the file so it can be executed by `./level03`. 

<details><summary> SOLUTION </summary>
  
* `su level04`

<p align="center">
👑 qi0maab88jeaj46qoumi7maus 👑
</p>
                                           
</details>

