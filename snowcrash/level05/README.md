<h1>LEVEL05</h1>


<h4>GETTING STARTED</h4>

Restart the VM, "You have new mail.".

<h4>/VAR/MAIL</h4>

The message "you have a new mail" displayed in your terminal usually indicates that you've received a system-generated email or a message from another user on your system. This mail is typically stored in your user account's mail spool file. On Unix-like operating systems, such messages can be system notifications, administrative messages, or emails from other users on the system sent through the command line.

There's a file `./level05`, if you cat it : ```*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05```

<h4>CRONTAB ENTRY</h4>

`*/2 * * * *`: This specifies when the command will run. It's made up of five fields separated by spaces, representing minute, hour, day of the month, month, and day of the week, respectively. The */2 means every 2 minutes. The asterisks (*) in the other positions mean "every" for their respective fields. So, this command is scheduled to run every 2 minutes of every hour, of every day of the month, of every month, and every day of the week.

`su -c "sh /usr/sbin/openarenaserver" - flag05`: This is the command that is scheduled to run. Let's break this down:

* `su`: This command is used to switch the current user account to another user account. Without any options, it switches to the root (superuser) account, but in this case, it's used to switch to a specific user account
* `-c "sh /usr/sbin/openarenaserver"`: The -c option tells su to execute the command specified in the following string, and then exit. Here, the command to be executed is sh /usr/sbin/openarenaserver. This means that the shell (sh) is invoked to execute the script located at /usr/sbin/openarenaserver
* `flag05`: This part is a bit unusual in its formatting, but it appears to indicate that the command should be run as the user flag05. 

<h4>/USR/SBIN/OPENASERVER</h4>

When you `cat` this script: 

```
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

This script, ran as sudo, deletes every file present in the directory `/opt/openarenaserver`. But it is ran as sudo/flag05. So add a script to /opt/openarenaserver with getflag’s output redirected to a new file which you need to store in tmp (or any other place where you can create a file that wont get deleted by this cron).

```
/bin/getflag > /tmp/flag.txt
```

<details><summary> SOLUTION </summary>
  
* `su level05`

<p align="center">
👑 viuaaale9huek52boumoomioc 👑
</p>
                                           
</details>

