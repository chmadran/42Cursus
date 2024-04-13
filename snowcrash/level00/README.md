<h1>LEVEL00</h1>


<h4>GETTING STARTED</h4>

Upon launching this level, you'll notice... nothing. If you `ls -la` in the home, there isn't anything specific. 
Now, you know you have to connect as `flag00` to then be able to launch `getflag` and retrieve the token, which is `level01`'s password.

So now, let's try and **find** anything related to `flag00`.

<h4>THE FIND COMMAND</h4>

The find command in Linux is designed for file and directory searches. So time to explore the diverse functionalities of the find command and enhance your file management skils. The syntax of the file command is : ```find [path] [options] [expression]```

So let's try and find files named or related to the user flag00, try `find / -user flag00` where 
* `/` is the starting point of the search, and it is the root directory of the filesystem so it stands for everywhere from this directory down...
* `user` tells find to only list files and directory owned by the user with the username specified after

Now, there's a lot of permission denied. To only keep whatever we have access to, you can redirect the output of stdeer and add the following to the command `find / -user flag00 2>/dev/null`

* `2>` is used to redirect the stderr stream
* `/dev/null` is a special file that discards all data written to it but reports that the write operation succeeded, it is used to dispose of unwanted output

There are many articles on how to use the find command, like [this one](https://www.ionos.com/digitalguide/server/configuration/linux-find-command/).


<h4>/USR/SBIN/JOHN</h4>

Let's read whats in this file suing `cat /usr/sbin/john`. It is not the password of `flag00` but it looks like it. So you'll need to find how it is encoded. There's a very useful website that gueses which encoding has been applied, [here](https://dcode.fr/).

Once you understand how the website work, you'll notice the password is encoded using ROT (and the famous Ceasar one), meaning all the letters are switched by 13 spots. Now you get the password : `nottoohardhere`

<details><summary>SOLUTION</summary>

* `su flag00`
* `nottoohardhere` as password
* `getflag`
* retrieve token
  
<p align="center">
👑 x24ti5gi3x0ol2eh4esiuxias 👑
</p>
                                           
</details>

