**Using more than one process through fork, wait, pause..**

*FORK() IN C*

Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.

It takes no parameters and returns an integer value. Below are different values returned by fork().

- Negative Value: creation of a child process was unsuccessful.  
- Zero: Returned to the newly created child process.  
- Positive value: Returned to parent or caller. The value contains process ID of newly created child process.  

```
#include <stdio.h>
#include <sys/types.h>
int main()
{
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}
```

The output would be hello eight times. Because the number of times ‘hello’ is printed is equal to number of process created. Total Number of Processes = 2n, where n is number of fork system calls. So here n = 3, 23 = 8

![image](https://user-images.githubusercontent.com/113340699/209313192-72331a5c-88ad-4ded-a2c2-63c9aa83db6f.png)

Source : https://www.geeksforgeeks.org/fork-system-call/

*PAUSE() IN C*

The pause() system call is used to make the calling process or calling thread sleep until one of the following events happened.

- The calling process receives the signal whose default behaviour is to kill the process. (OR)  
- The signal handler execution is finished.  
- In both the cases the pause() system call returns -1.  

The pause() function blocks until a signal arrives. User inputs are not signals. A signal can be emitted by another process or the system itself.

Pressing Ctrl-C for instance, causes your shell to send a SIGINT signal to the current running process, which in normal cases causes the process to be killed.

In order to emulate the behaviour of pause in ISO C99 you could write something like the following. The code is commented, if you have a question about this implementation, please ask.

```
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static void     handler()
{
  printf("Signal caught\n");
  done_waiting = 1;
}

void    my_pause()
{
   *  In ISO C, the signal system call is used
   *  to call a specific handler when a specified
   *  signal is received by the current process.
  signal(SIGINT, handler);
  done_waiting = 0;
  while ( !done_waiting )
    ;
}

int     main()
{
  my_pause();
  printf("Hey ! The first call to my_pause returned !\n");
  my_pause();
  printf("The second call to my_pause returned !\n");
  return (0);
}
```

*KILL() IN C*

The kill () system call is widely used to transmit signals to multithreaded programs or traditional processes. Based on its numeric values, the integer PID parameter has multiple implications. If the PID value is more than zero, the sig signal is issued to the process’s thread group whose PID matches PID. If the PID value equals zero, the sig signal is transmitted to all thread groups in the same process group as the caller process. If PID equals -1, Except for swapper (PID 0), init (PID 1), and current, the signal is given to all processes.

Overall, kill is the system call used to send signals using the following syntax : kill(PID, signal).


Source: https://stackoverflow.com/questions/15992574/how-does-pause-work
Source : https://www.nayab.xyz/man2/pause-system-call-in-C
