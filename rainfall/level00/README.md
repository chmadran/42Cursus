# level0


The security report relating to the configuration of the OS kernel, and a particular file, level0, is not relevant for this level. 

After downloading the file on our machine (using scp), decompiling it on [dogbolt.org](https://dogbolt.org/), we can see there is a blocking `if` in the `main`. Therefore, to bypass it, we will change the return value of `atoi`. Return values are stored in the `eax` variable. 

Using `gdb`, we can launch the binary, disasemble main, set a breakpoint after atoi returns and change the value to one that will allow us to bypass the `if`, in our case it's the int `423`, or `0x1a7`. Once this is passed, a shell is launched and because there's a `setuid` on the file, it is launched as `level1`. 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/9a30c2be-a94d-45ab-a47c-fddcb9be2bb2)

We need to start making the effort to only look at gdb and not to decompile the file first. Indications like `cmp` mean there's most likely an `if` statement. For this level, we just start the executable with 423 as argument and then `id` we notice we are `level1`, we can `pwd`, head to `home/user/level1` and `cat .pass`. 



