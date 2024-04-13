# level07

When looking in `gdb` through `info functions` we see there's a function `m()` that could be interesting. It's actually not called anywhere in `main()` if we go through it carefully.. So let's check what `m()` does : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/c757cac5-3c50-4ab2-9f1d-dc2405c61450)

So it prints the time (so random) but also a string located at `0x8049960`, mmmh. Looking back at `main`, we see it's printing the content of of the `.pass` file into `c`. 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/57946ed4-e9b5-4e42-a246-e4e0c43104b6)

Then `c` is printed in `m()`, so it must be our string located at `0x8049960`, our goal here being to display `c` by calling `m()`

![image](https://github.com/chmadran/rainfall_42/assets/113340699/c8ee19d5-d5f1-4c9d-b185-f2c110f5afa6)

One vulnerability here is the `strcpy()` call, we could call `m()` at the end of our payload :     

- the offset is **20**, careful here it's not EIP who gets overflowed        
![image](https://github.com/chmadran/rainfall_42/assets/113340699/f71e85f3-b8f9-44cb-83a1-611c153f1e5a)

- address of m : `0x080484f4`   
![image](https://github.com/chmadran/rainfall_42/assets/113340699/67290b77-3cf2-4c1f-819c-dca693f84b81)

- address of puts : `0x8049928`    
![image](https://github.com/chmadran/rainfall_42/assets/113340699/762b6d71-6aac-4c21-9f81-803f9fad4a91)


SO to create the payload : 

1. overflow `strcpy` with 20 of padding : `python -c 'print "A"*20'`
2. replace argv[2] by `puts()'s address` : `$(python -c 'print "A"*20 + "\x28\x99\x04\x08"')`
3. now overflow with address of `m()` so it gets replaced `$(python -c 'print "A"*20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')`

We know that because when we overflowed strcpy, the overflow was found in `edx` which is `strcpy()`'s second argument : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/469952a1-a70e-4203-b48f-268c08d11d84)
