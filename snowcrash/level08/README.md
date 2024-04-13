<h1>LEVEL08</h1>


<h4>GETTING STARTED</h4>

The executable reads and displays a file on the standard output. You have a file token but when passing it as parameter you get the error message cannot read token.

<h4>FILE</h4>

If you decompile the executable you actually notice the protection is based on the hardcoded filename `token`.
Therefore, you can pass another file that actually points to `token`. 
Give yourself your rights on your home again, `chmod 755 .`
Then create a symbolic link to token `ln -s token test` and send `./level08 test`.

<details><summary> SOLUTION </summary>
  
* `su level09`

<p align="center">
👑 25749xKZ8L7DkSCwJkT9dyv6f 👑
</p>
                                           
</details>
