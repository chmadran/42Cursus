<h1>LEVEL11</h1>


<h4>GETTING STARTED</h4>

Another day another executable, se `strings ./level11.lua` to see whats inside. It's a program that opens a connexion and waits for a password to compare it with a hashed one. It executes an echo of the password pipes with a sha1sum to get the hashed version, but there is not input validation at the echo stage so its vulnerable to anything. 

<h4>INJECTION VULNERABILITY</h4>

The script employs io.popen to execute a shell command that hashes the password provided by the user. This function opens a process that executes a given command string in the operating system's shell, capturing its output. The command concatenates user input directly into the shell command:

If an attacker were to inject a command such as "; echo hello; #, the echo hello command would execute, but its output would be captured by the io.popen call and stored in data, not printed to the console or terminal from which the Lua script was launched. For the attack to have a visible effect (e.g., printing "hello" to the terminal), the script would need to include a command to specifically print the captured output, which it does not.

So simply redirect to a file `$(getflag) > /tmp/flag`.

![image](https://github.com/chmadran/snowcrash_42/assets/113340699/5daee2ac-0bf3-4fb3-93c4-28d25dc52605)


<details><summary> SOLUTION </summary>

* `su level12`
  
<p align="center">
👑 fa6v5ateaw21peobuub8ipe6s 👑
</p>
                                           
</details>

