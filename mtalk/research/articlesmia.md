Dans les systèmes de type Unix, il y a plusieurs mécanismes pour envoyer des signaux aux processus. Tous ces mécanismes font appel à la notion de groupes de processus.  

Chaque processus dans le système appartient à un groupe identifié par un entier positif, le PGID (process group identifier). C’est un moyen facile d’identifier les processus apparentés. Par défaut, les processus fils appartiennent tous au groupe de leur père. Cela permet au système d’envoyer un signal à tous les processus dans un groupe à la fois.  

**Envoyer un signal depuis le clavier**  

Depuis le shell dans notre terminal, il y a trois raccourcis de clavier qui nous permettent d’interrompre tous les processus en avant-plan en cours d’exécution :  
- ctrl-c : envoie SIGINT pour les interrompre,  
- ctrl-\ : envoie SIGQUIT pour les tuer,  
- ctrl-z : envoie SIGTSTP pour les suspendre.  

Bien sûr, ces raccourcis n’affectent pas les tâches de fond, c’est à dire les processus en cours d’exécution en arrière-plan. Mais comment faire pour envoyer l’un des 28 autres signaux ?  


**Envoyer des signaux avec la commande kill**    
Pour envoyer un autre type de signal depuis notre terminal, il faudra utiliser la commande kill. Et ce, même si le signal en question n’a rien à voir avec la terminaison du processus ! Certains shells possèdent leur propre commande kill interne. Ici, nous parlerons uniquement du programme qui se situe dans /bin/kill.  

Tout d’abord, il faut trouver le PID ou le PGID du ou des processus auxquels on souhaite l’envoyer un signal. Pour afficher le PID d’un processus, on peut utiliser les commandes pidof , pgrep, top ou encore, comme on l’a vu plus haut, ps.  


**Envoyer un signal avec l’appel système kill en C**    
Dans un précédent article sur la création et la terminaison de processus fils, on a rapidement vu l’appel système kill de la bibliothèque <signal.h>. Il existe plusieurs autres appels systèmes pour demander au système d’envoyer un signal depuis notre programme en C, mais celui-ci est le plus communément utilisé. Rappelons son prototype :  

```int kill(pid_t pid, int sig);```   

Cet appel système fonctionne de la même manière que la commande /bin/kill décrite ci-dessus. Ses paramètres sont :  

- pid : l’identifiant du processus ou du groupe de processus auquel envoyer le signal. On peut ici spécifier :  
un entier positif : le PID d’un processus,  
un entier négatif : le PGID d’un groupe de processus,  
0 : tous les processus dans le groupe du processus appelant,  
-1 : tous les processus dans le système pour lequel le processus appelant a la permission d’envoyer un signal (sauf le processus 1, init). Voir la page de manuel kill (2) pour la question des permissions.  

- sig : le signal à envoyer au processus.  
La fonction kill renvoie 0 en cas de succès et en cas d’erreur, -1, avec errno mis à jour pour indiquer les détails de l’erreur.  



