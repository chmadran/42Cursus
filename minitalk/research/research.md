**What is a Global Variable in C?**  
A variable defined outside the scope of all the functions is known as a global variable in C. The global variables have a global scope, hence these variables can be accessed and modified by any function, structure, or in any scope in C. Global variables are defined before the main() function. They can not be defined inside or after the main() function. They need to be named gb_nameofvariable as per 42's norme.

source : https://www.scaler.com/topics/global-variable-in-c/

**What's a signal?**  
Signals are software interrupts sent to a program to indicate that an important event has occurred. The events can vary from user requests to illegal memory access errors. Some signals, such as the interrupt signal, indicate that a user has asked the program to do something that is not in the usual flow of control.

source : https://www.tutorialspoint.com/unix/unix-signals-traps.htm

Un signal concerne un message qu'un processus envoie a un autre. C'est un moyen de communication d'un processus a un autre pour demander un type d'action ou changer l'etat d'un processus. Une commande qui va nous permettre d'envoyer un certain type de signal c'est kill. Kill possede des options qui permettent de faire plein d'actions. Grace a kill -l on liste les signaux.

e.g installer xeyes  
    puis kill -SIGSTOP; ou kill -19; ou kill -STOP; ou kill -s SIGSTOP; puis numero du PID  
    le processus n'est pas tue mais l'application est freeze/mise en sommeil  
    avec kill -SIGCONT; ou kill -18; ou kill -COUNT; ou kill -s SIGCOUNT; puis numero du PID  
    le processus se redemarre  

    kill -19 PID ; sleep 5 ; kill -18 PID <- pour jouer avec kill, sleep, kill
    
source : https://www.youtube.com/watch?v=hJ0f1Pd-v2Y

*RECP : Signaux*
- Evenements externes qui changent le deroulement d’un programme, de
maniere asynchrone  
- Emis par un autre processus ou par le systeme ´

*Comportement a la reception d’un signal (selon le signal et les reglages) :*  
 Terminaison de l’execution  
 Suspension de l’execution (le processus pere est prevenu)  
 Rien : le signal est ignore  
 Execution d’une fonction d´efinie par l’utilisateur  
 
 --> SIGUSR1 & 2 can be used with user defined functions instead of predefinite ones like other signals.

**PID**  
*What is it?*  
Applications qu'on peut utiliser, se cache derriere des processus. Un processeur permet des traitement/ de faire des calculs sur ces programmes. Un processu spar applicaiton generalement, mais les navigateurs par exemple ont plusieurs processus en meme temps, un par onglet.  

*How to access it?*  
La commande ps nous permet de voir le PID (processus ID). Le time est le temps depuis lequel elle a ete calculem le CMD c'est par ou on est passe. 
Le flag '-elf' nous pemet d'obtenir une liste plus detailee.  
Le flag '-auwx' nous permet d'obtenir une liste plus detailee mais une liste plus graphique.  

*Which information needs to be known?*  
Peu importe le nombre de processsus, chacun de ces processus utilise le meme executable/ la meme base de code. Ce qui differencie un executable d'un autre c'est le contexte d'execution et le suivi de son execution.

*What's a processus?*  
Un processus (en anglais, process), en informatique, est un programme en cours d'exécution par un ordinateur. De façon plus précise, il peut être défini comme :
- un ensemble d'instructions à exécuter, pouvant être dans la mémoire morte, mais le plus souvent chargé depuis la mémoire de masse vers la mémoire vive ;
- un espace d'adressage en mémoire vive pour stocker la pile, les données de travail, etc. ;
- des ressources permettant des entrées-sorties de données, comme des ports réseau.

L'exécution d'un processus dure un certain temps, avec un début et (parfois) une fin. Un processus peut être démarré par un utilisateur par l'intermédiaire d'un périphérique ou bien par un autre processus : les « applications » utilisateur sont des ensembles de processus.

source : https://fr.wikipedia.org/wiki/Processus_(informatique)
