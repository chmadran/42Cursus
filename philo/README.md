# philosopher started 16/02

Pour compiler : make, ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]

TESTER : https://github.com/ethanolmethanol/philosophers42tester.git

"Chaque philosophe doit etre represente par un thread"

A program can be quickly executed by introducing concurrency using threads. Each thread can execute part of the same task (e.g., summing elements of an array), or it can allocate the same task for different clients in a client-server architecture.

**What is concurrent programming?**

Concurrency generally refers to events or circumstances that are happening or existing at the same time.

In programming terms, concurrent programming is a technique in which two or more processes start, run in an interleaved fashion through context switching and complete in an overlapping time period by managing access to shared resources e.g. on a single core of CPU.

This doesn’t necessarily mean that multiple processes will be running at the same instant – even if the results might make it seem like it.

**How to create a simple thread in C?**

1. Include the library and link option for successful compilation

```#include <pthread.h>```
```gcc -g -pthread main.c -o main```

2. When you create a thread, it executes a function you pass to it, called a routine. The type of variable for a thread is pthread_t. Now, to create it the function is pthread_create and it's arguments are :
- a pointer to the pthread_t created ```pthread_creater(&example,```
- attributes, usually set to NULL so set to default attributes ```pthread_creater(&example, NULL```
- the function executed when passing the function ```pthread_creater(&example, NULL, &ft_routine```
- finally the argument passed to the routine, sually NULL ```pthread_creater(&example, NULL, &ft_routine, NULL)```

One thing to note, the function passed has to be a void pointer.

3. Finally, we have to wait for the thread to finish its execution before the process does so call another function called pthread_join that is the wait for threads to which you pass :
- the thread ```pthread_join(example```
- a pointer that gets the result from the thread  but you can pass NULL ```pthread_join(example, NULL)```


Source : https://www.educative.io/answers/what-is-concurrent-programming
Source : https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=1

** Difference between processes and threads**

Processes can contain multiple threads but you cannot have mutliple processes in one thread. Secondly, when we fork, we duplicate all the variables in the other process. With threads, that is not the case. All threads can access all variables. They all have a common address space, memory is shared accross all threads.

**What is a race condition and how to solve this issue?**

Race condition happens when there is a lot of iterations. with long processes there is a risk that a second pr else thread gets created and it creates a race condition. A mutex is like a lock around a section of code. It can be initialised with pthread_mutex_init and with every initialisation comes a destroy to not forget. To check if the mutex has been locked, if a thread is ongoing, and to unlock after a thread is done can be done using a fonciton ```p_thread_mutex_lock``` / ```p_thread_mutex_unlock```.


```
int mails = 0;
int lock = 0;
pthread_mutex_t mutex;

void *routine(){
  for (int i = 0; i < 100000; i++) {
    if (lock == 1) {
      // wait until the lock is 0
    }
    lock = 1;
    mails++;
    lock = 0;
  }
}
```

OR

```
void *routine(){
  for (int i = 0; i < 100000; i++) {
    pthread_mutex_lock(&mutex);
    mails++;
    pthread_mutex_unlock(&mutex);
    lock = 0;
  }
}

int main(void) {
  pthread_t t1;
  pthread_t t2;

  pthread_mutex_intit(&mutex, NULL);
  if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
    return 1;
  }
  if (pthread_create(&t2, NULL, &routine, NULL) != 0){
    return 2;
  }
  if (pthread_join(t1, NULL) != 0) {
    return 3;
  }
  if (pthread_join(t2, NULL) != 0) {
    return 4;
  }
  pthread_mutex_destroy(&mutex);
}
```


Source : https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3

**Creating threads in a loop**

This piece of code is particularly interesting.. but the problem here is that it will start a thread, terminate it, then start a new thread, then terminate it and so on. Where what we're looking for is to start all the threads in paralell.



```
int main (int ac, char **av)
{
  pthread_t th[4];
  int i;

  pthread_mutex_init(&mutex, NULL);
  for (i = 0; i < 4; i++) {
    if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
      perror("Failed to create a thread);
      return 1;
     }
    if (pthread_join(th[i], NULL) != 0) {
      return 2;
     }
  }
...
}

SO instead this is correct - you'll notice the amended second loop.

int main (int ac, char **av)
{
  pthread_t th[4];
  int i;

  pthread_mutex_init(&mutex, NULL);
  for (i = 0; i < 4; i++) {
    if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
      perror("Failed to create a thread);
      return 1;
     }
    for (i = 0; i < 4; i++) {
      if (pthread_join(th[i], NULL) != 0) {
      return 2;
      }
    }
  }
...
}
```

**How to get a return value from a thread**

It all happens in pthread_join, its syntax is pthread_join(pointer to thread, result expected as void**). It takes a reference to a pointer (double pointer) and its going to set the value within it to whatever was set as second argument.


stopped at 7/29 : https://www.youtube.com/watch?v=HDohXvS6UIk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=7

STEP BY STEP

1. LE PARSING

Verifier que aucun des arguments n'est à 0, il ne peut pas y a voir aucun philosphe, ou aucun temps pour manger etc.
Verifier qu'il y a 5 ou 6 arguments, pas moins, pas plus.

2. INITIALISATION

Initialiser la strucutre qui contient les data générales / partagées et entrées en parametre.
Initialiser la structure par philosophe qui contiendra toutes les infos specifiques à chacun.
Initialiser les mutex qui seront utilisées et les threads.

3. LA ROUTINE

La routine est la fonction passée en paramètre des threads. La routine tournera jusqu'à ce qu'un des evenements declencheur arrive (mort d'un philosophe ou ils ont tous mangés).

Introduire les complexités une par une :
- ajouter un mutex printing qui permet de ne pas melanger les strings lorsqu'ils s'écrivent
- print "is sleeping", "is thinking"
- ajouter un wait du temps de dormir entré en paramètre
- necessité d'avoir deux fourchettes, le cercle se fait dans l'initialisation des id de la left fork qui est celle de philo[0] puis ils sont mutex rightfork/leftfork dans la routine eat

Conditions de mort :
- ajouter un timestamp pour la derniere fois que le philo a mangé pour etre sur qu'on respecte le fait que si le philo n'a pas mangé depuis av[1] alors il meurt. Puis compare le moment ou il a mange pour la derniere fois - le moment actuel. Si c'est plus grand que le time to die rentre en parametre alors change le int (eatingtime), et change le int death to 1. 
- ajouter un compteur de fois ou le philo a mangé si jamais tous les philos ont mangé le nombre de fois requis (av[5]) alors on change le int all_ate to 1. Attention l'entree dans cette loop doit etre sous condition que la variable ait ete initialisee dans la structure (presence d'un av[5] a la base)

-> si all ate == 1 ou si death == 1 alors on exit.

NOTE TO SELF : 
- Invalid read is because your exit condition of your while is going too far
- visualiser can help understnd : https://nafuka11.github.io/philosophers-visualizer/