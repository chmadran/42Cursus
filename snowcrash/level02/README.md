<h1>LEVEL02</h1>


<h4>GETTING STARTED</h4>

Upon launching this level, you'll notice a `.pcap` file in the home. Any time you have an executable, you can try and lauch it. If you can't  `cat` a file (because its in binary format, it looks weird) then decompile it to see the source code and understand what it does. 


<h4>SCP</h4>

Now, since you need to get the file on your machine from the VM, this is the first time you'll use `scp`. SCP (secure copy) is a command-line utility that allows you to securely copy files and directories between two locations.

When transferring data with scp, both the files and password are encrypted so that anyone snooping on the traffic doesn’t get anything sensitive. SCP uses the SSH protocol for both authentication and encryption. The syntax is as follows : `scp [OPTION] [user@]SRC_HOST:]file1 [user@]DEST_HOST:]file2`

So in our case `scp -P 4242 level02@192.168.56.3:/home/user/level02/level02.pcap .` you are then prompted to enter the user's password, but after that you get a 100% download if all is well.


<h4>.PCAP FILE</h4>

A **.pcap file (Packet Capture Data)** is a file format used to store network traffic captured by network sniffing tools like Wireshark, tcpdump, and others. These files contain the packet data of a network's traffic, including the headers and payloads of individual packets, and can be used for detailed analysis and troubleshooting of network issues.

**Wireshark** is on 42 computers, you can use it to open the .pcap file. It is a free and open-source packet analyzer used for network troubleshooting, analysis, software and communications protocol development, and education. 

For protocols that establish a conversation or session (like TCP), you can right-click on a packet and select ``Follow > TCP Stream``. This shows you the entire conversation between the two endpoints, making it easier to read the exchanged data in sequence. This opens a file that contains the password but under this format ``ft_wandr...NDRel.L0L``. 

<h4>HEX DUMP</h4>

Wireshark attempts to display data in ASCII by default, but if the data uses a different encoding (e.g., UTF-8, ISO-8859-1), some characters might not display correctly. In our case, since we suspect that some characters in the data exchanged within a TCP stream (or any other protocol stream) are not displaying correctly in Wireshark, viewing the data as a hex dump can be very helpful. 

This approach allows you to see both the hexadecimal representation of the data and the ASCII interpretation side by side, which can be particularly useful for identifying non-printable character. In our case, we notice : 

* 0x7F : this is DELETE
* 0x0D : this is Carriage Return 


<details><summary> SOLUTION </summary>

* `su flag02`
* `ft_waNDRelL0L` as password
* `getflag`
* retrieve token
  
<p align="center">
👑 kooda2puivaav1idi4f57q8iq 👑
</p>
                                           
</details>

