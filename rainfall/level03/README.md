# level3

Here, we will be conducting a **format string vulnerability** since we have a printf that just prints whatever string is passed to`stdin`. [This](https://web.ecs.syr.edu/~wedu/Teaching/cis643/LectureNotes_New/Format_String.pdf) is a good source to understand how for example, if we can make the format argument "%x.%x.%x.%x", printf will pop off four stack values and print them in hexadecimal, potentially leaking sensitive information.

What we are interested in here, is the call opening the shell. We know that using `%n`, we can actually write the number of characters printed so far into the adress specified. Therefore, we can bypass the `if` statement of this `binary` by crafting a payload that sets the variable `m` to 64 (which is 0x40 in hexadecimal).

To format the payload of the attack we need : 
- the address in which we want to amend a value : thats the `eax` stored before the `cmp` so `0x804988c`
- the value we want to store at this address : 64 as the `cmp` is with `0x40` that is 64
- the spot where we want to make the modification : here 4th argument as we can see when we print e.g `AAAA %x %x %x %x` that the 4th value is where the len gets stored in the stack 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/e7413391-826f-4157-823b-e723480fef60)

So craft the payload as follows : 

`python -c 'print([address where modification occurs] + [padding to get to the nbr you want] + %[argument specifier]$[n])'`

`python -c 'print "\x8c\x98\x04\x08"+"A"*60+"%4$n"' > payload`
