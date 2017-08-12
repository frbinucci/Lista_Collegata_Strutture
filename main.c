/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: franc
 *
 * Created on 12 agosto 2017, 13.58
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"

//Definizione delle costanti necessarie a migliorare la leggibilità del menù utente.
#define ADD 1
#define DELETE 2
#define PRINT 3
#define EXIT 0

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Variabile necessaria al caricamento di un nuovo contatto.
    Contact newContact;
    //Definisco una lista inizialmente vuota.
    nodePtr list = NULL;
    //Variabile necessaria alla ricerca mediante numero del contatto da eliminare.
    char number[20];
    //Variabile necessaria al funzionamento del menù utente.
    int selectedOption;
    //Il programma stampa il menù utente fino a quando l'utente non decide di 
    //interrompere l'inserimento mediante l'opzione "0".
    do
    {
        //Stampa del menù mediante la funzione "instructions()", definita nella libreria
        //"utilities.h".
        instructions();
        //Ottenimento dell'opzione scelta dall'utente.
        scanf("%d",&selectedOption);
        puts("");
        //Controllo dell'opzione scelta.
        switch(selectedOption)
        {
            case ADD:
                loadContact(&newContact);
                insert(&list,newContact);
                break;
            case DELETE:
                printf("%s","Insert the telephone number of the contact you want to eliminate: ");
                scanf("%19s",number);
                puts("");
                bool check = deleteByNumber(&list,number);
                if(check)
                {
                   puts("Contact eliminated with success!!!"); 
                }
                else
                {
                    printf("Unable to find the number %s in the list, please retry...",number);
                    puts("");
                }
                puts("");
                break;
            case PRINT:
                printList(list);
                break;
            case EXIT:
                break;
            default:
                printf("Unknown option: %d, please retry...",selectedOption);
                puts("");
                puts("");
                break;   
        }
    }while(selectedOption!=EXIT);
    
    return (EXIT_SUCCESS);
}

