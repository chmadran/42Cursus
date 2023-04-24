# minitalk

Started on December 9th.

**Research.txt**  
This is where I will store all my research.

STEP BY STEP : 

1. Le serveur est lance, son PID est imprime
printf("%d", getpid());

2. Cote client, lancer le programme avec en parametre 1. le PID de serveur et 2. une chaine de charactere  

3. Cote client, traduire la chaine de charactere passee en parametre en binaire (0 et 1)  

4. Cote serveur, recevoir SIGUSR1 = recevoir 0 et recevoir SIGUSR2 = recevoir 1

5. Decoder le message cote serveur, et attester que le serveur a bien recu chaque bit et l'imprimer  


Allowed functions are as follows :   
```
◦ write  
◦ ft_printf (self coded only)  
◦ signal  
◦ sigemptyset  
◦ sigaddset 
◦ sigaction  
◦ kill  
◦ getpid  
◦ malloc  
◦ free  
◦ pause  
◦ sleep  
◦ usleep  
◦ exit  
```

Some help ? https://github.com/Abensett/5.-Minitalk

How to edit a README : https://github.com/Simplonline-foad/utiliser-markdown/blob/master/README.md

Mes erreurs : 

- relink sur le Makefile   
- Ajouter la regle make bonus  
- Fichier separe pour les bonus   
- Verifier pid = -1 sinon crash  

