<h1>LEVEL10</h1>


<h4>GETTING STARTED</h4>

Another day another executable, decompile the assembler and see that it tries to open a file you pass as parameter to this client programme. If you don't have access to the file, it exits.

<h4>THE FILE SYSTEM</h4>

You will notice in the script you 1. check whether you have access to the file and later 2. you check if you can open it. Therefore, there's a window of vulnerability. 

The `access()` function in C, used to check the calling process's permissions for accessing a file (such as whether the file can be read, written, or executed), can indeed introduce security vulnerabilities, especially in programs that run with elevated privileges (e.g., setuid programs). One well-known vulnerability related to `access()` is the time-of-check to time-of-use (TOCTTOU) race condition.

The **TOCTTOU (Time Of Check To Time Of Use)** vulnerability occurs when there is a time gap between checking a condition (like file permissions with access()) and using the result of that check to perform an operation (like opening the file). An attacker can exploit this gap to manipulate the file system's state and cause the program to behave in unintended ways.

The server script that works : **https://firelightflagboy.github.io/posts/snowcrash/level10/**


<details><summary> SOLUTION </summary>

* `su level11`
  
<p align="center">
👑 feulo4b72j7edeahuete3no7c 👑
</p>
                                           
</details>

