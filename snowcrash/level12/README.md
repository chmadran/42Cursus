<h1>LEVEL12</h1>


<h4>GETTING STARTED</h4>

Another day another executable...

<h4>INJECTION VULNERABILITY</h4>

This script does not allow for the same kind of injection due to the uppercasing and space-truncation behaviors, which are still rudimentary forms of input sanitization.

* create symbolic link from /tmp/GETFLAG to /bin/getflag
* we can use wildcard to execute within x //GETFLAG
* but we need to get the result somehow, so need to redirect to a file
* but that wont work since we cant have spaces
* so use the error log (of apache) ~tail /var/log/apache2/error.log
* there if you redirect to >%262 (you need to encode “&”) 

You can also create a con

<details><summary> SOLUTION </summary>

* `su level12`
  
<p align="center">
👑  g1qKMiRpXf53AWhDaU7FEkczr 👑
</p>
                                           
</details>

