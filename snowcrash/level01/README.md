<h1>LEVEL01</h1>


<h4>GETTING STARTED</h4>

Upon launching this level, you'll notice... nothing. If you `ls -la` in the home, there isn't anything specific. Now, let's explore the file system in Linux as we don't seem to find anything.

<h4>THE FILE SYSTEM</h4>

Try `tree -L 1 /`, that is *show me only the 1st Level of the directory tree starting at / (root)* since -L specifies how many levels should be displayed : 
* `/bin` for binaries (and not trash) contains the apps/programms you can run, basically all the built in commands.
* `/boot` to start up the system
* `/dev` for device files, mainly generated at boot time or when you plug e.g a USB/Webcam or any other device
* `/etc` for everything to configure containing most, if not all, the system's configuration files (users/their **password** etc)
* `/home` users' personal directories
* `/lib` for libraries
* `/sbin` for superuser binaries
* `/usr` for everything that needs to be shared by applicatins and services, actually in modern linux distributions, most builtins are actually in `/usr/bin` and everything in`\bin` points to `/usr/bin`
* `/srv` contains data for servers
*  `/tmp` contains temporary files usually placed there by applications that you are running
*  `/var` originally given its name because its contents was deemed variable (it changed frequently) like logs 

![image](https://github.com/chmadran/snowcrash_42/assets/113340699/cd769f11-9310-4cc6-aa2c-356fc2d27a72)

<h4>/ETC/PASSWD</h4>

If you cat /etc/passwd you'll see all the passwords are `x` except flag01. This file is accessible to all users on the system and traditionally held the hashed passwords for user accounts, among other details like the user ID (UID), group ID (GID), home directory, and login shell. However, for security reasons, the actual password hashes have been moved to a separate file, `/etc/shadow`, which is readable only by the root user or members of a privileged group. This separation enhances system security by limiting access to encrypted password data.

![image](https://github.com/chmadran/snowcrash_42/assets/113340699/c1290e60-66b1-4d72-9bb8-b06daa39974c)

Now, use Hashcat/John the Ripper and crack the password :) 

<details><summary> SOLUTION </summary>

* `su flag01`
* `abcdefg` as password
* `getflag`
* retrieve token
  
<p align="center">
👑 f2av5il02puano7naaf6adaaf 👑
</p>
                                           
</details>

