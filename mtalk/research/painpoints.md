
**BITWISE (&) AND OPERATOR**

It takes two bits at a time and perform AND operation. AND (&) is a binary operator, it takes two numbers and perform bitwise AND. Result of AND is 1 when both bits are 1. Then move to the '1' to the left to compare each bit of the byte. 

0000 0000 & 0000 0001 = 0 
0000 0001 & 0000 0001 = 1

**BITWISE (|) OR OPERATOR**

It takes two bits at a time and perform OR operation. OR (|) is a binary operator, it takes two numbers and perform bitwise OR. Result of OR is 0 when both bits are 0. Then move the one to the left to fill out each bit of the byte when it's a 1. As soon as there is a 1, compare to 1 and al good !


0110 0000 | 0000 0001 = 0110 0001

**SIGACTION**

Two ways to handle receiving signals : functions signal or system call sigaction. Here we use sigaction in server because it collects information on the entity who sent the signals and we need its PID to send back a confirmation signal.

- SA.SA_SIGACTION = ft_handlesignal : Si SA_SIGINFO est indiqué dans sa_flags, sa_sigaction (plutôt que sa_handler) indique la fonction gestionnaire de signaux pour signum. Cette fonction prend le numéro du signal comme premier argument, un pointeur sur un siginfo_t comme second argument et un pointeur sur un ucontext_t (transtypé en void *) comme troisième argument.


- SA.SA_FLAGS = SA_SIGINFO : Le gestionnaire de signal recevra trois arguments, et non plus un seul. Dans ce cas, il faut utiliser le membre sa_sigaction et non pas sa_handler. Cet attribut n'a de sens que lors de la mise en place d'un gestionnaire de signal.

SIGINFO itself is a structure, and it changes the function receiving the signal to add (i) the info structure we'll take the client pid from and two a void str because it's prototype is the following, and not just an int now.

![image](https://user-images.githubusercontent.com/113340699/209431971-75d7b9e7-b318-4a07-97c0-1d7c7f7db1bc.png)


Source : https://breezetemple.github.io/2018/01/25/How-to-Write-Advanced-Signal-Handlers-in-UNIX/

**USLEEP** 

It is necessary to suspend the process of sending signals by, here 100 microseconds, so that it creates an order in the sending of signals (a queue). Otherwise, each signal is sent at the same time and this results in losing some bits, some characters..

It's in microseconds compared to sleep which is in seconds.
