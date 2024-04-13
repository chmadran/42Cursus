# level1


There's an executable `level1` when you `disas main` in `gdb`, you will only see a call to a function `gets`. But that function doesn't seem to do anything in particuler. With strings, after you scp the file, you'll see there's somewhere a `Good...Wait what ?` as well as `/bin/sh` underneath.

So we can infer there's another function than `gets` that opens a shell, you can find it in `gdb` using `info functions` (or in the online decompiler), it's the `run` function. So the goal here is to call `run` that will open a shell and with the setuid will allow us to read `.pass`. 

It's important to note at this stage that we will conduct our first buffer overflow attack and that is only possible because some protections are disabled. Those protections are as followed : 

<details><summary>NX </summary> Modern operating systems mark areas of memory as non-executable (using the NX bit on x86 processors, also known as Data Execution Prevention - DEP on Windows). This prevents an attacker from executing arbitrary code via a buffer overflow by marking the stack and heap as non-executable, so even if an attacker manages to inject malicious code into these areas, the processor will refuse to execute it.</details>
<details><summary>Position independent executables (PIE)</summary> allows executable code to run at any memory address, not at a specific address. The code is compiled in such a way that it can execute properly regardless of its absolute address, which complements ASLR by making it harder for attackers to predict the location of specific instructions or structures in memory.</details>
<details><summary>Address Space Layout Randomization (ASLR)</summary> ASLR randomly arranges the address space positions of key data areas of a process, including the base of the executable and the positions of the stack, heap, and libraries. This randomness makes it more difficult for an attacker to predict target addresses for buffer overflow attacks, such as specific locations where shellcode might be placed.</details>
<details><summary>Stack Canaries</summary>A stack canary is a security mechanism that protects against buffer overflow attacks by placing a small integer (the "canary") in memory just before the stack return pointer. The value of the canary is checked before a function returns. If a buffer overflow occurs, it's likely to overwrite the canary value, and the change can be detected, preventing the overflow from corrupting the return address and hijacking the program's execution flow.</details>


<h4>ANATOMY OF MEMORY</h4>

If you run a buffer overflow attack since our program is vulnerable, then you can run `run` instead of `gets`. Some backgroud info, this is what memory looks like : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/2486f282-48db-4bec-af68-aa069e81c39c)

And more precisely, this is what the stack looks like : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/d6d2eb77-881c-4b7e-be93-95d1dd5e5450)

When the buffer space is filled up with characters, it grows downward. If you sent characters at it like a bunch of As, you should reach the EBP and stop. When there's a buffer overflow attack, you reach over the EBP and eventually into the EIP meaning you can use this return address to point to another existing function in the program :

![image](https://github.com/chmadran/rainfall_42/assets/113340699/2d36c069-cb2d-4c3c-a3e0-96425491d361)


<h4>CRAFTING A PAYLOAD</h4>

The **offset** is the distance in bytes from the start of the buffer (where your input begins) to the return address location on the stack (EIP). Calculating the offset to the return address in a buffer overflow exploit is crucial for crafting a payload that precisely overwrites the return address on the stack with the address of the function you want to execute (like `run` in our case).

Begin with a payload that fills the buffer and gradually increases in size. For example, if you know the buffer is around 100 bytes, start with 100 "A"s and then add 4 "B"s to see if you can overwrite the return address. Run the program under a debugger like gdb, and look at the register used as the return address (EIP on x86) when it crashes. If it's overwritten with your "B"s (0x42424242), you've found the rough location of the return address. You can refine your approach by adjusting the number of "A"s and "B"s to pinpoint exactly where the return address begins. This manual binary search helps you identify the offset without automated tools.

But some tools have been crafted to help you do that quicker, one is called `pattern_create.rb` and `pattern_offset.rb` which are tools part of the `metasploit` framework. `pattern_create.rb` simply creates a pattern then `pattern_offset` will indicate what the offset is based on the EIP value you enter. The command syntax is `./pattern_create.rb -l [arbitrary len]` and then `./pattern_offset.rb -l [len of pattern] -q [address of segfault]`. In our case, we get an offset at **76**.

Then find the address of the function you want to insert at `EIP` / as return address and add it to the payload in `little endian` because x86 and x86_64 architectures (developed by Intel and AMD) use little-endian byte ordering. 

Then `-` used with cat waits for additional input from stdin (i.e., your keyboard input). Whatever you type after executing the command will be appended to the content of payload. To signal the end of your input from stdin, you would press `Ctrl+D` (EOF in Unix/Linux environments) if you're manually entering additional data. In our case, since we'll be opening a shell, we need to make sure we leave `stdin` open. 


```level1@RainFall:~$ python -c "print('\x90'*76 + '\x44\x84\x04\x08')" > payload```     
```level1@RainFall:~$ cat payload - | ./level1```    
```cd ../level2```
```cat .pass```

Ressources: 
- [explanation on buffer overflow attack](https://www.youtube.com/watch?v=1S0aBV-Waeo)
- [guide](https://www.cobalt.io/blog/pentester-guide-to-exploiting-buffer-overflow-vulnerabilities)

<h4>SOME CONCEPTS</h4>

<details><summary>Registers</summary>Registers are fast, small storage locations in a processor for storing data that is being processed. Using buffer overflows, attackers can overwrite the contents of certain registers, allowing them to control the flow of execution.</details>

<details><summary>EAX</summary>The EAX register is a general-purpose register that holds the result of arithmetic operations and stores the address of the processed data. In buffer overflow exploitation, the EAX register stores the address of a pointer to the input buffer that contains the attacker's malicious code.</details>

<details><summary>EBP</summary> The EBP register is used as a base pointer to locate data on the stack. In buffer overflow exploitation, the EBP register can locate the return address stored on the stack, which the attacker will overwrite with the address of their malicious code.</details>

<details><summary>ESP</summary>The ESP register is used as a stack pointer to keep track of the top of the stack. In buffer overflow exploitation, the ESP register can locate the buffer that is being overflowed and identify the adjacent memory locations that will be overwritten.</details>

<details><summary>EIP</summary> The EIP register holds the address of the next instruction to be executed by the program. In buffer overflow exploitation, the attacker will attempt to overwrite the contents of the EIP register with the address of their malicious code.</details>

<details><summary>Little Endian</summary>
In little-endian format, the least significant byte (LSB) of a word is stored in the smallest address, and the most significant byte (MSB) is stored in the highest address. For example, the hexadecimal number 0x12345678 would be stored as 78 56 34 12 in memory.   

The prefix x in \x when writing hexadecimal values in strings (especially in programming languages like Python, C, and others) doesn't directly relate to little-endian or big-endian notation. Instead, \x is a standard escape sequence that indicates the start of a hexadecimal value within a string.    

</details>
