# Net_practice

<h2>TCP/IP </h2>
Une suite de protocoles cad de regles (organisee en couche) utilises pour le transfert des donnees sur Internet, c'est a dire que lorsque deux ordinateurs veulent communiquer entre eux via internet, les donnees echangees vont etre mise en forme selon des regles qui sont toujours les memes afin que chaque machine puisse se comprendre et afin que le transfert des donnees soient fiables. C'est comparable a l'envoi d'une lettre par la poste.

![image](https://github.com/chmadran/Net_practice/assets/113340699/759ca622-c641-432f-9011-1e0180100664)

Dans un ordinateur tourne differentes applications (e.g navigateur, messagerie..). Chaque application est identifiee par un port. Par exemple, une application de serveur web est identifiee par le port 80. Cela permet a un message lorsqu'il est envoye vers un ordinateur, de savoir a quelle application s'adresse le message. L'adresse IP permet de savoir quel chemin emprunter. Enfin, chaque carte reseau possede elle aussi une identification. L'adresse MAC est l'adresse d'une machine.  Les routeurs permettent de relier les sous-reseaux entre eux. S'il relie deux sous reaseaux ils auront deux adresses IP et donc deux cartes reseaux avec deux adresses MAC (ou trois si 3 interfaces et ainsi de suite).

 ![image](https://github.com/chmadran/Net_practice/assets/113340699/25b272ca-2ca4-43c8-b8ac-032d2f588ce9)


**SCHEMA DU FLUX DES DONNEES DANS LA SUITE DES PROTOCOLES TCP/IP**

![image](https://github.com/chmadran/Net_practice/assets/113340699/3a5a2e68-879b-449f-9569-04c079e9e86c)


Pour voir les echanges de donnees, on peut utiliser ce logiciel de simulatin reseau : https://ent2d.ac-bordeaux.fr/disciplines/sti-college/2019/09/25/filius-un-logiciel-de-simulation-de-reseau-simple-et-accessible/

<h2>IP ADDRESS</h2>
An IPv4-adress (where IP stands for Internet Protocol), is an identifier for a computer or device on a network. It is a 32-bit numeric address divided into 4 "blocks", each 4 numbers/each 8 bits, that is 1 octet, separated by a period. The number range in each octet is 0-255 i.e.: 

`192.168.100.1` turns into `11000000.10101000.01100100.00000001`
So the min. value of one "block" is `0` and the max. value is `255`. Why ? 

![image](https://github.com/chmadran/Net_practice/assets/113340699/99aaeed2-2d57-40c9-a3bc-6e3a891fd09c)

To make things easier, we can alias an IP address with a human-readable name called a domain name. For example (at the time of writing; IP addresses can change) google.com is the domain name used on top of the IP address 142.250.190.78. So using the domain name is the easiest way for us to reach a computer over the Internet.

An IP address consists of : 
* a network address : a unique number assigned to a network
* a host address : a unique number assigned to host within that network, such as computers, tablets etc

* ![image](https://github.com/chmadran/Net_practice/assets/113340699/f2368cc7-6997-40f1-8937-9ee6f3b4a6e5)

To tell which part is which, thats where the subnet mask comes in. It is a number that ressembles an IP address and it reveals how many bits in the IP address are used for the network by masking the network portion of the IP address.

![image](https://github.com/chmadran/Net_practice/assets/113340699/f1ae5270-4960-46b4-91c7-031b26d5ff14)
![image](https://github.com/chmadran/Net_practice/assets/113340699/b51f8023-aec9-43ce-bdcd-92a15580b761)
![image](https://github.com/chmadran/Net_practice/assets/113340699/bf737a13-3b1c-4042-a2d5-654409d66459)

The following special address-ranges are reserved for Private Networks:    
`10.0.0.0 – 10.255.255.255`  
`172.16.0.0 – 172.31.255.255`  
`192.168.0.0 – 192.168.255.255`  

The following address-range is reserved for so called loopback addresses / localhost:  
`127.0.0.0 – 127.255.255.255`

There is some more special ip-ranges, but for this project, you only need to remember those above.
A public IP address is an IP address that can be accessed directly over the internet and is assigned to your network router by your internet service provider (ISP). A public (or external) IP address helps you connect to the internet from inside your network, to outside your network.

A private IP address is an address your network router assigns to your device. Each device within the same network is assigned a unique private IP address (sometimes called a private network address) — this is how devices on the same internal network talk to each other.

<h2>MASK ADDRESS</h2>

The same logic applies to the network-mask:
`255.255.255.0` turns into `11111111.11111111.11111111.00000000`

The network-mask, subnet-mask or in our project only called mask is there to decide which range of ip-adresses are part of the same subnet. There are 2 different ways of writing the mask:  
* "Dot-decimal notation": `255.255.255.0`  
* "Class Inter-Domain Routing" or "CIDR": `/24`  (this counts the number of 1s in the subnet mask)

![image](https://github.com/chmadran/Net_practice/assets/113340699/733b64ca-78ff-429b-aabe-7f3132bec987)

The more usable ip-addresses you need in one subnet, the less subnets you will be able to create. Special to the mask is, after one bit was 0 there can't be any 1 bit's anymore. So the only available numbers are:

`255 (binary: 11111111)`  
`254 (binary: 11111110)`  
`252 (binary: 11111100)`  
`248 (binary: 11111000)`  
`240 (binary: 11110000)`  
`224 (binary: 11100000)`  
`192 (binary: 11000000)`  
`128 (binary: 10000000)`  
`0 (binary: 00000000)`  

Through which `255.255.255.0` is a valid mask and `255.255.128.128` is not a valid mask.

One thing to note is how you write in binary is based on : 
![image](https://github.com/chmadran/Net_practice/assets/113340699/c84d8029-9d62-4217-8093-42f4a97c3477)
Or : 

![image](https://github.com/chmadran/Net_practice/assets/113340699/dc9e0264-a24f-4984-a21c-5f14e05687a3)


**In order to have the ability to send packages between two IP-addresses they either need to be part of the same network or they need to be connected by a router which is part of both subnets.**

<h2>Switches</h2>

A switch will enable you to connect more than two devices to the same network. It can turn one ethernet port into many, is a bridge with a lot of outputs.

Its only purpose is to distribute packages to its network.
To see a working example, you can take a look at Level 3.

<h2>Routers</h2>

As previously mentioned a router is an interface which enables communication between different networks.
A router has the ability to be part of multiple networks, in Netpractice this is visualized by the so called Interface.

A Router creates a very own local network with each devide you want to connect having its own local IP address like a flat number in a building where each appartment has the same street address. Web traffic gets to the appropriate device within your home, as routed by the router.

<h2>Subnetting</h2>

Why does an IP address have a network part? Its manageability, its for breaking down a large network into smaller netoworks or subnetworks which is known as **subnetting***. Let's say we have a large amount of computers in one huge computer. Now when one computer wants to talk to another computer, it needs to know how and where to reach that computer.  

And it does this by using **broasdcast**. A broadcast is when a computer sends out data to all computers on a network so it can locate and talk to a certain computer. In order to prevent every computer from broadcasting to every other computer (asking who is [insert IP Address] at the same time) then the network needs to be broken down into smaller networks. To do that, we use **routers**. Broadcasts do not go past routers, they stay within a network. Thats why IP addresses have a network part. 

**Subnetting** is done by changing the default subnet mask by borrowing some of the bits from the host portion. 
![image](https://github.com/chmadran/Net_practice/assets/113340699/6d3c87a3-0817-4a8d-ab87-620ce9b5cd0b)
![image](https://github.com/chmadran/Net_practice/assets/113340699/88e9a814-2149-41fb-932a-19fb72b59753)

It doubles the number of networks but it divides the number of hosts.

IP addressses ans subnet masks come  in 5 different classes but 3 of these are for commercial use. This is the chart of the IP Addresses and the Default Subnet Masks which are class A,B, and C. A very large amount of networks needed? You'll be Class A as you'll have the larget HOST PART of your IP address (3 octets). Class A can produce up to 16Millions, Class B 65000, and Class C 254 IP addresses.

![image](https://github.com/chmadran/Net_practice/assets/113340699/74becdc2-2431-415b-94db-5c0125ee6220)

<h2>NAT : Network address Translation</h2>
Service used in routers, its purpose is to translate a set of IP Addresses to another set of IP Addresses. The NAT service preserves the limited amount of IPv4 public IP Addresses. When created, they didnt realise how big the internet was going to become, even though there were 4 billion IPv4 addresses available, the engineers thought this would be enough. To prevent shortage, engineers developped NAT and private IP Addresses.

There are two different types of IPV4 Addresses : 
* public ones are publicly registered on the internet (needed to go on the internet)
* private ones not publicly registered so cannot access the internet directly (only used internally, inside a home or business). Your router assigns your private IP.

Our router assigns, inside our devices inside our home or business, a private IP despite the fact that we could have a public IP if we asked our Internet Service Provider but that would be...

When we need to access the internet, then our private IPs are translated by NAT to the one public IP Address that we have been given. NAT translates a set of IP addresses to a set of IP addresses. It translates both ways if a computer interacts with a computer outside the network.  

  ![image](https://github.com/chmadran/Net_practice/assets/113340699/67aac65a-5a4a-4675-9117-c0b3952ad430)

<h2>HOW TO DETERMINE HOW TO WRITE IP ADDRESSES</h2>

**IP ADDRESS**

Find number of subnets and the range  

 Range will be `256 - last 8 bites - 2(broadcast/network entries) = range of each network`  
 For example : `255.255.255.128` so `256 - 128 - 2 = 126` meaning there will be two network, 1 from `1-126` and   the other one from `129-255` where `0, 128` are emtries and `127, 256` are exits.

![image](https://github.com/chmadran/Net_practice/assets/113340699/3226f327-6e50-498e-8b0e-f53db727d815)

**ROUTING TABLES**

A route contains 2 fields, the first one is the destination of outbound packets, the second one is the next hop of the packets.  

The **destination** default is equivalent to 0.0.0.0/0, which will send the packets indiscriminately to the first network address it encounters. A destination address of 122.3.5.3/24 would send the packets to the network 122.3.5.0.  

The **next hop** is the IP address of the next router (or internet) interface to which the interface of the current machine must send its packets.  

**THE INTERNET**

This level introduces the internet. The internet behaves like a router. However, if an interface is connected directly or indirectly to the internet, it cannot have an IP address in the mentioned above reserved private IP ranges.

1. The next hop of the internet is already entered, and matches the IP address of the Interface R2. Therefore we only need to bother with the destination of the internet.

The internet must send its packets to Client A. To do so, the internet's destination must match the network address of Client A. Let's find the network address of Client A:
Client A's mask is 255.255.255.128, which is equivalent to /25. This means that the first 25 bits of its IP address are its network address. We know then that the first 3 bytes (24 bits) of its IP address make part of its network address:

`40.178.145.?`  

We now only need to find out if the 25th bit is a 1 or a 0.
If we convert the number 227 to binary, we get 11100011. The first digit, which corresponds to the 25th bit, is a 1. Since only the 25th bit is part of the network address and not the remaining 7 bits, we get 10000000 for the last byte of the network address, which is 128 in decimal.

The full network address is:

`40.178.145.128`  

With a range of `40.178.145.129 - 40.178.145.254` for its host addresses.

We can now put this address of `40.178.145.128` in the Internet destination. The /25 following the destination address represents the mask applied to its address.

A destination of `40.178.145.227/25` is equivalent to the destination address 40.178.145.128/25, since the mask of /25 will turn all the bits after the 25th to 0 to get the destination's network address.

<h2>IPv6</h2>
In the future, there will be no more NAT / private IP addresses because every device will have its own public IP address as the code looks more like : 

![image](https://github.com/chmadran/Net_practice/assets/113340699/cc0ebc53-6714-4667-8d32-132d202df500)


<h3>Interesting Ressources</h3>    

* https://github.com/tblaase/Net_Practice  
* https://toufa7.medium.com/new-subnetting-34fadfb86c70  
* https://www.youtube.com/watch?v=s_Ntt6eTn94  
* https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/How_does_the_Internet_work  
* https://www.youtube.com/watch?v=FTUV0t6JaDA  
* https://github.com/lp-ob/NetPractice  
