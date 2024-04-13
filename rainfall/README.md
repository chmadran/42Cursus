# rainfall_42

![image](https://github.com/chmadran/rainfall_42/assets/113340699/4d25b608-bf98-4fc3-af10-457b4408859e)


<h2>PREAMBLE</h2>

This project is the second cybersecurity project of Ecole 42. It consists in completing 15 CTF (Capture the Flag) challenges, mostly focusing on Buffer Overflow attacks. 

<h2>HOW IT WORKS</h2>

To complete this project, we will have to use a VM with an ISO that has been provided with the subject. If the configuration is right, we will get a simple prompt with an IP and a login request. We can always login with user:levelXX password:levelXX. But this user has limited permissions. 

Once logged-in, you will have to find a way to read the `.pass` file with the `levelX` user account of the next level (X = number of the next level).

<h2>HOW TO START</h2>

Step by step :
* Create your VM (64 bits), store it in `/sgoinfre`
* Download the iso that's in the subject
* Upon launching your VM for the first time, add the rainfall.iso image
* You should be prompted to enter a login, enter level0 as login and password
* Connect in ssh from your terminal, e.g `ssh level00@[vm's ip address] -p 4242` (see below for help on ssh set up)
* Good luck !

<h2>BUFFER OVERFLOW ATTACKS !</h2>

A buffer is a temporary allocated memory space. A buffer overflow is a security vulnerability that occurs when a program or process can write more data than the memory buffer can hold. As the name suggests, the extra data will overflow into the memory adjacent to the buffer and overwrite that data. Attackers can exploit a buffer overflow to control, crash or modify a process. 

By default, programming languages like Python or Java perform runtime bounds checking making it virtually impossible for a buffer overflow to occur. But there is a performance cost due to the extra code being run and therefore programming languages like C or C++ don't perform this runtime bounds checking. There is no builtin function to determine if the data going into the buffer is larger than the buffer. Therefore, they are the only languages in which a buffer overflow is possible. 

Often, the buffer we're talking about are local variables and will be placed in an area of memory called the stack. The return address represents the location in code we are going to go back to when we're done with the current function. A user cannot see or interact with the return address, normally. Generally, a buffer overflow results in a program crash because the overwritten return address does not point to a valid program instruction. 

But if someone can control the content of a buffer overflow, you can carefully chose a return address that points to a place in code that you want to execute. If there is no pre existing function that we can return to, you can actually write your own code and then jump back to executing your own code.

A couple of types:  : stack based overflow, heap based overflow, format string, GOT exploit. 

<h2>STEPS TO EXPLOIT</h2>

- Find vulnerability
- Find offset
- Find replacement value for EIP (other function's address with like `print [func name]` in little endian)
- Create payload

When a program calls a function :
* the parameters to the functon are either pushed onto the stack (32b programs) or moved into registers (64b programs)
* the address of the next instruction in the caller's function is pushed onto the stack (the return address)
* the address of the first instruction in the called function is moved into the IP register
* The called function saves the old BP on the stack
* The called function moved the current SP into BP
* The function begins execution 

<h2>USEFUL INFORMATION</h2>

Stack frames contain :
* function parameters
* local variables
* a reference to the calling process' stack
* the address of the calling process' next instruction to executive when the current function finishes 

**GDB CHEATSHEET**
* info [function name]
* disas [function name] / dissassemble [function name]
* b *[address] / break *[address]
* x/20x $[register]
* c / continue
* s / step
* r / run
* x/i [address]
*  shows a single instruction at [address] - to get the exact address its on the right ![image](https://github.com/chmadran/rainfall_42/assets/113340699/261b6eee-3530-4e10-a75e-a70e4a6413b4)
 side 
* quit
* info proc mappins to see the mapped regions, their size etc

`strace [executable]`
`checksec --file=[binary name]` -> to check file protections     
`python -c print()` OR `ruby -e 'puts()'` -> to create payloads
`0x1020304` = `/x04/x03/x02/x01` -> converting in little endian
`scp -P 4242 user@IP:/file/path [destination]`
`ssh user@IP -p 4242`

Very good playlist, really the only thing you need [here](https://www.youtube.com/watch?v=Sr1x-3BRYF8&list=PLLTI453cNzfn2_9Q9KXb9lbF233gvsQOJ)

How They Hack: Buffer Overflow & GDB Analysis [here](https://www.youtube.com/watch?v=V9lMxx3iFWU)


