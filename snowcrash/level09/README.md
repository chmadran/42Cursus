<h1>LEVEL09</h1>


<h4>GETTING STARTED</h4>

If you cat the file `token` you notice it has unprintable characters. 

<h4>DECODING</h4>

When you compile the executable and pass a string as parameter you notice : `aaa` becomes `abc` and `111` becomes `123` so it seems like each character gets switched by its index. 

Write a program that decodes the token, who has been encoded by the executable. Meaning you need to reverse the ascii character displayed to its original form by substracting its index.

<h4SCRIPTING</h4>

Then `./a.out $(cat token)`

```
#include <stdio.h>

int main(int ac, char **av) {

        (void)ac;
        int i = 0;
        char c;
        while (av[1][i]) {
                c = av[1][i];
                printf("%c", (c - i));
                i++;
        }
        printf("\n");
        return 0;
}
```

<details><summary> SOLUTION </summary>
  
* `su level10`

<p align="center">
👑 s5cAJpM8ev6XHw998pRWG728z 👑
</p>
                                           
</details>
