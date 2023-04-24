https://www.youtube.com/watch?v=jF-1eFhyz1U  
https://www.youtube.com/watch?v=PErrlOx3LYE

**STEP BY STEP on how to handle signals**  

1. Add signal.h
Signal related functions and signals are.

2. Create a structure - it's better for portability, some versions cant handle simple function, more on the topic below
Inside, we will tell the programm how to handle the signals.

```
struct sigaction sa;                     // declare a sigaction structureand name it e.g "sa"
sa.sa_handler = &ft_handle_signal;     // setup pointer to the function that will be called when we receive a certain signal (called handler mostof the time) so modify the structure of sigaction to initialise the function as the one we'll create
sigaction(SIGUSR1, &sa, NULL);          // hook this struct to the proper signal 
sigaction(SIGUSR2, &sa, NULL);         // hook this struct to the proper signal 
```

2.OR simply call a function 

```
e.g signal(SIGUSR1, &ft_handle_signal);
```

3. Create the function handling the response to receiving a signal

```
void  ft_handle_signal(int sig)
{
  printf("Signal RECEIVED");
}
```

*ATTENTION / POINTS A NOTER*

Il est necessaire d'utiliser la structure/sigaction afin de recevoir les informations necessaires (via siginfo) pour dire au client que chaque charactere a bien ete recu. A defaut de faire ca, tous les characteres ne seront pas imprimes.

The mask of the handler must be specified. This is not in the above. See below.  

**SIGACTION**  

The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.
signum specifies the signal and can be any valid signal except SIGKILL and SIGSTOP. If act is non-null, the new action for signal signum is installed from act. If oldact is non-null, the previous action is saved in oldact.

The sigaction function examines the action associated with a particular signal. We are now talking about the arguments in the parameter of the sigaction function. The first one is int ‘sig,’ as the data type reveals that it is a number that refers to the signal that is recognized already. The sigaction function sets the action and associates it with the signal. The sig argument that is used must be in the <signal.h> library.

Constant struct sigaction is a pointer that is first referred to as NULL mostly. If so, then the sigaction function examines the action that is defined currently to handle sig. This will not modify or cancel this action. And if the new pointer is not referred to as NULL value, it will point to a sigaction structure. The action identified specifically in the sigaction structure then becomes the new action associated with sig.

The sigaction structure is defined as something like : sigaction(SIGHUP, &newact, &oldact)

![image](https://user-images.githubusercontent.com/113340699/209142659-fed36bc9-0045-443c-96ad-a23e02dc47f6.png)


This is the sigaction structure : 

```
struct sigaction {
  void  (*sa_handler)(int);
  sigset_t sa_mask;
  int sa_flags
}
```

Whenever we are executing the handler function, we amy receive another signal. We may have to stop the process. In that case,  

Source : https://www.youtube.com/watch?v=_1TuZUbCnX0
Source : https://linuxhint.com/c-sigaction-function-usage/
