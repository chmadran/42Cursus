**STEP 1 : Connect server and client through PID**

Minitalk is a communication program. Therefore, client and server must be able to exchange information. The way to do this is through UNIX signal and the server's PID (Process IDentifier).   

As a quick reminder, the server must first be launched and display it's PID. Then the client is launched with, as parameters, the server's PID and a string of characters. Finally, the server displays the string of characters passed as argument to client. It is important to note that the program, on the server side, has tobe expecting a signal otherwise it would just be terminated, hence the use of the ```pause()``` function.

The ```pause()``` function suspends a process pending a signal. Here I will use an infinite loop to get the server to be an ongoing process until the program is actually exited by the user using ctrl + c / z / SIGKILL.

**STEP 2 : Encode message and create the ping pong process**

We will need to send the message using UNIX Signals (SIGUSR1 & SIGUSR2). Therefore, we will encode the message to binary in order to send 0s and 1s. To do this, we simply go through each bit and use the kill system call to send (with the PID we have from above) USR1 or USR2.  

On the server side, we have a ping pong system that acnowledges each bit reception and prints, every 8 bits, the char it corresponds to. This prevents the resulting char form being truncated.  

Le système de ping pong (le serveur qui valide au client la bonne réception d un signal) permet d éviter toute désynchronise entre client et serveur.Après chaque signal, en fait il n'y a pas de queue de signal, tout peut arriver un peu dans le désordreDonc après chaque signal reçu ton serveur peut envoyer un SIGUSR1 au client pour dire « ok tout va bien, envoie la suite ».

En realite, il suffit de mettre un sleep dans l'encodeur pour etre sur que chaque signal s'envoie l'un apres l'autre.

**STEP 3 : Print the resulting char**

See endecoding.md

**STEP 4 : Les bonus**

1. Confirmer la reception du message du serveur au client

*Cote sender*  
des 8 bytes recues, ajouter -> kill(info->si_pid, SIGUSR2);  
dans le prototype du handler, rajouter le parametre siginfo_t *info  

In the structure of sigaction, si_pid is the PID of the sender of the signal in the first place.  

*Cote client*  
accomoder la reception du signal qu'on va envoyer 
ici une simple fonction signal fait l'affaire (pas besoin de stocker des infos)  


ATTENTION, cela change aussi : 
- ```sa.sa_handler = &ft_handle_signal``` devient ```sa.sa_sigaction = ft_handle_signal```
- le prototype de ```void ft_handle_signal(int sig)``` devient ```void ft_handle_signal(int sig, sigcation *info, void *s)```
2. Etre capable d'afficher les characteres, meme smileys



WATCH OUT : 
- add sleep to your encoder/sender function otherwise there is no queue in the order the signals are sent and some letters will be lost and not printed  
- fill out sigaction with mask?  
- 


A few important concepts : 
- UNIX Signals
- Processes
- Process Identifiers
- Signal Handlers 
