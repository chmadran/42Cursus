# push_swap

**STEP BY STEP**

1. Check the user input (CHECK_ARG.C)

- there cannot be twice the same number;
- or a character that is not a number;
- or a negative;

Be mindful of numbers starting with a 0. For example, when a user puts '04' and '4', this should display an error message. Therefore, we had to double check whether there are doubles by checking the 'ints' we put in the chained list (because errors are not showing when we look at it as chars.) This is to be found in pws-check_arg.c

2. Create stack A, anf fill it out with the user input from top to bottom (INIT_STACK.C), at the same time make sure you create a function that frees the stack(s) at the end - best time to deal with mem allocation is early on (UTILS_STACK.C)


3. Get the size of stack A, based on its size you will send it to different sorting algos. At this point, its important to note that we create a function that checks if the stack is already sorted. If it is, then there will be no need to go through any of the algos and the whole program just return 0/NULL. (IS_SORTED.C)  

- if there are only two inputs, and the list is not sorted, simply reverse stack a (sa)  
- there are three inputs, and the list is not sorted, simply sort the tiny list  
- otherwise, use the big sorting algo   


4. To sort more than 2 values, we will use indexes. By that we mean that we will add an info to the element structure called index, referring to the spot where the number should be. We can the calculate the moves that are the less expensive and which will end up sorting the list.


In UTILS_STACK.C : 
- first add the int index to the structure of the element in the .h
- then the function will add as index the highest value it finds 
- then it will decrease the stacsize and add this int as index to the second highest number 
- and so on


*4.A*   
To sort 3 values in 2 moves or less ( FT_SORT3.C), find the highest index of the three numbers and then
- if the first number of the pile is the highest number than ra (move it to the bottom)
- if the second number of the pile is the highest number than rra (move it to the bottom by pushing the last number on top)
- if none of the above but the first number is higher than the second, sa (swap first and second)

*4.B*   
To sort more than 3 values : 
- push all the elements of stackA to stackB except 3 : (i)sort these 3 numbers, (ii)when pushing, push first evertyhing that is under the stacksize / 2
- then assigns a position to each element of a stack from top to bottom in ascending order (in list struct add position)

**RUN THE TESTER**

Pour utiliser le checker : 
1. chmod 777 le fichier car sinon pas la permission necessaire
2. Ecrire bash pour se mettre en mode bash 
3. run la commande suivante : ARG=" 1 2 3"; ./executable $ARG | ./checker $ARG

**RUN THE VISUALIZER**

https://github.com/o-reo/push_swap_visualizer
To run the above :   

IF AT HOME  
- Install a C++ compiler (gcc, clang,...)  
- Install cmake   

-Move push_swap_visualizer inside push_swap  
-Inside push_swap_visualizer, mkdir : 'build'  
-cd in the build folder and type : 'cmake ..'  
- 'make'  
- move the executable push_swap to bin  
- run the visualizer with ./bin/visualizer  


Listes chaines : https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/Listes%20cha%C3%AEn%C3%A9es.htm
