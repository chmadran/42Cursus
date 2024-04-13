# level5

Ok so we see a couple of functions that could be interesting here `n()` and `o()`   

![image](https://github.com/chmadran/rainfall_42/assets/113340699/33523a1c-a298-4da3-9546-6044d101cbd7)

We see `main()` calls `n()` but not `o()`,     

![image](https://github.com/chmadran/rainfall_42/assets/113340699/9ac672b3-86bb-4c8e-96b5-333e8057e509)

let's see what's in `o()`.. interesting there's a system call opening a shell, perfect we know we have to launch `o()`

![image](https://github.com/chmadran/rainfall_42/assets/113340699/0907e9b8-6306-43e6-b04c-ed810f930afb)

We notice a vulnerability in `n()` through `printf()` not sanitizing user input, we'll be calling `o()` there right after its print, instead of `exit()` 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/b55bdb7b-aab4-472e-878b-481cf14575de)

Now, crafting the payload...

- The argument position is 4th    

![image](https://github.com/chmadran/rainfall_42/assets/113340699/04e1a1b9-ce77-4b71-a32f-19fd553cc8a0)

- The address of `o()` : `0x80484a4` = `134513828` in decimal 

- The address of `exit()` : `0x8049838`   

![image](https://github.com/chmadran/rainfall_42/assets/113340699/5420a6c2-7bbd-431c-8f98-e048f88cbf48)

SO payload syntax will be `[address to be replaced] + %[replacement address in decimal - 4 bytes already written]d + %[argument position]$n`

THEREFORE `python -c 'print("\x38\x98\x04\x08" + "%134513824d" + "%4$n")'`

[This](https://www.youtube.com/watch?v=t1LH9D5cuK4) is a good source to understand how to write the script.
