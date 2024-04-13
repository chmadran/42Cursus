# level8

Such a difficult decompiled program to understand............

When switching it to pseudo-C code then you start understanding that what gets printed to the screen are two addresses : one is the address of the `auth` local variable and the second one is the address of the `auth` variable.

We can also see that to unlock the shell, we need to fill out `auth[8]`, else you will only be prompted to write in a `Password: ` field. But `auth` is only allocated 4 bytes : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/394a3a39-5a40-4d90-86d8-c91f072077a7)

When you start testing the program, you notice that service is in memory next to auth, so we could write at auth[8] using service. We notice the increase is +10 and auth[8] is +32 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/11e8d499-08c7-429a-99b3-058d9078414c)

So to bypass the `if` statement and allow us to launch the shell, write 32 bytes further than the `auth` variable using `service`, and initialise `auth`. One thing to note here is that you must write `auth` followed with a space.

![image](https://github.com/chmadran/rainfall_42/assets/113340699/e9f3cf16-8d19-403d-84ee-e8a2c01fc41a)


