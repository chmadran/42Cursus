<h2> MINITALK </h2>

GRADE : 125/100

<h3> How to launch minitalk : </h3>

1. Le serveur est lance, son PID est imprime
printf("%d", getpid());

2. Cote client, lancer le programme avec en parametre 1. le PID de serveur et 2. une chaine de charactere

3. Cote client, traduire la chaine de charactere passee en parametre en binaire (0 et 1)

4. Cote serveur, recevoir SIGUSR1 = recevoir 0 et recevoir SIGUSR2 = recevoir 1

5. Decoder le message cote serveur, et attester que le serveur a bien recu chaque bit et l'imprimer

