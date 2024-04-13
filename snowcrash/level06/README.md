<h1>LEVEL06</h1>


<h4>GETTING STARTED</h4>

There's a `.php` script, which uncompiled displayes two functions. 
There's an executable which seems to execute the script and pass an argument to it, it takes a file as parameter.

<h4>FUNCTIONS X AND Y</h4>

The functions `preg_replace` will be executed twice with the user input from the file passed as parameter. If in the file, something starts with `[x` then the script will take it into account and execute anything as owner of the file that is `flag06` because of the setuid. 

`preg_replace` is a function in PHP that utilizes regular expressions (regex) to search for patterns within strings and replace those patterns with specified replacements, the syntax is : 

`preg_replace($pattern, $replacement, $subject, $limit = -1, &$count = null)`

A Regular Expression (regex) is a powerful tool used in computing for matching patterns within text. It's a sequence of characters that forms a search pattern, which can be used for text search and text replace operations. Regex allows you to describe and match patterns in text. For example, you can use it to check whether a string contains a certain pattern (e.g., an email address or a phone number) or to find all occurrences of a pattern within a string. Beyond searching, regex can be used to replace text, split strings into arrays based on a pattern, or even rearrange parts of the string. Regex is commonly used for validating user input, such as ensuring an email address is in the correct format, a password meets specific criteria, or a date is valid.

You need to inject `getflag` in the script, add x at the beginning so it takes it into account and then send for execution ```$ echo '[x {${exec(getflag)}}]' > /tmp/flag``` and after `./level06 /tmp/flag`

<details><summary> SOLUTION </summary>
  
* `su level06`

<p align="center">
👑 wiok45aaoguiboiki2tuin6ub 👑
</p>
                                           
</details>

