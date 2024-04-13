<h1>LEVEL13</h1>


<h4>GETTING STARTED</h4>

The script we're dealing with exits unless it's run by a user with UID 4242. But there is no user with a uid 4242.


<h4>INJECTION VULNERABILITY</h4>

When decompiling the executable, you can actually notice that you have the function to decode the token, it's `ft_des`. Reproduce `ft_des` and you'll be able to decode the token by passing it as parameter. 


<h4>BYPASSING GETUID</h4>

An alternative by my mate Pierrick and Alan, was to override `getuid` by creating a library through LD_PRELOAD that gets called first, and setting the uid to 4242 by default. Execute it with `gdb` to see the result.

```
gcc -shared -fPIC -o libgetuid_override.so getuid.c -ldl
then put this lib as a default lib :
export LD_PRELOAD=/var/crash/libgetuid_override.so
```

<details><summary> SOLUTION </summary>

* `su level12`
  
<p align="center">
👑  2A31L79asukciNyi8uppkEuSx 👑
</p>
                                           
</details>

