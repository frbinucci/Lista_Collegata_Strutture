/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "utilities.h"
//------------------------------------------------------------------------------
//---------IMPLEMENTAZIONE DELLE FUNZIONI NECESSARIE----------------------------
//Definizione della funzione "insert()", necessaria al caricamento di un nuovo contatto.
bool insert(nodePtr *list,Contact newContact)
{
    //Allocazione della memoria necessaria per un nuovo elemento della lista collegata.
    Nodo *newNode;
    newNode = malloc(sizeof(Nodo));
    bool success=false;
    //Il controllo seguente è atto a verificare che non si siano riscontrati problemi
    //durante l'allocazione del nuovo nodo.
    if(newNode!=NULL)
    {
        //Inizializzo il nuovo nodo della lista.
        newNode->nextPtr = NULL;
        newNode->info = newContact;
        //Verifico se il nodo inserito è il primo della lista, mediante la funzione
        //"isEmpty()".
        if(!isEmpty(*list))
        {
            //Nel caso in cui il nodo da caricare non sia il primo inizio il ciclo
            //di scansione della lista. Questo consente di scorrere la lista dei contatti
            //fino a posizionarsi all'ultimo nodo della lista (contrassegnato dal campo
            //nextPtr settato a NULL). 
            nodePtr indexPtr = *list;
            while(indexPtr->nextPtr!=NULL)
            {
                indexPtr = indexPtr->nextPtr;

            }
            //Una volta raggiunto l'ultimo nodo della lista, il valore relativo
            //al puntatore al nodo successivo viene aggiornato con il puntatore
            //restituito dalla funzione "malloc()", nell'allocazione del nuovo nodo.
            indexPtr->nextPtr = newNode;
            success=true;
        }
        else
        {
            /*Nel caso in cui la lista sia vuota, aggiorno direttamente il valore
             * del parametro list.*/
            *list = newNode; 
            success=true;
        }       
    }
    else
    {
        /*Nel caso in cui l'allocazione della memoria non riesca, viene presentato
         * un messaggio di errore.*/
        puts("Unable to allocate memory...");
    }
    /*La funzione restituisce "true" se l'inserimento del nuovo nodo è avvenuto con
     * successo, "false", in caso contrario.*/
    return success;
}
//Definizione della funzione "deleteByNumber()", necessaria all'eliminazione di un nodo
//dalla lista. La modalità di ricerca del numero da eliminare si basa sul numero di telefono,
//che viene ricevuto come secondo parametro dalla funzione.
bool deleteByNumber(nodePtr *list,char number[])
{
    bool success=false;
    nodePtr indexPtr;
    nodePtr hold;
    /*Verifica se la lista sia vuota o meno. Nel caso in cui la lista sia vuota occorrerà
     * modificare il puntatore "list", passato alla funzione per riferimento.*/
    if(!isEmpty(*list))
    {
        //Controllo se l'elemento da eliminare è il primo della lista.
        if(strcmp((*list)->info.telephoneNumber,number)!=0)
        {
            //Ricerca dell'elemento da eliminare, nel caso in cui non sia il primo della lista.
            indexPtr = *list;
            //Il ciclo di ricerca prosegue fino a quando non ci si posiziona nel nodo precedente 
            //rispetto a quello da eliminare, oppure si arriva alla fine della lista.
            while(indexPtr->nextPtr!=NULL && strcmp(indexPtr->nextPtr->info.telephoneNumber,number)!=0)
            {
                indexPtr = indexPtr->nextPtr;
            }
            //Nel caso in cui l'elemento venga trovato, si procede a rimuoverlo dalla lista
            //liberando la memoria, per poi modificare il riferimento dell'ultimo nodo al nodo
            //successivo.
            if(indexPtr->nextPtr!=NULL)
            {
                success=true;
                hold = indexPtr->nextPtr->nextPtr;
                free(indexPtr->nextPtr);
                indexPtr->nextPtr = hold;
            }
        }
        else
        {
            //Nel caso in cui l'elemento da rimuovere sia il primo della lista
            //dovrà essere modificato il riferimento contenuto all'interno del
            //puntatore "list".
            success=true;
            hold = (*list)->nextPtr;
            free((*list));
            (*list)=hold;
        }
    }
    //La funzione restituirà "true" nel caso in cui l'eliminazione del contatto sia
    //avenuta con successo.
    return success; 
}
//Implementazione della funzione "isEmpty()".
bool isEmpty(nodePtr list)
{
    //La funzione resituisce valore "true" se il puntatore al primo elemento della
    //lista assume valore "NULL". ciò significa che la lista è vuota.
    return list==NULL;
}
//Implementazione della funzione "printList()", necessaria alla stampa della lista dei contatti.
void printList(nodePtr list)
{
    puts("***Contact list:***");
    //Definizione del puntatore necessario a scansionare tutta la lista.
    nodePtr index = list;
    //Ciclo di stampa: il ciclo procede fino a quando non si giungerà all'ultimo elemento della lsita
    while(index!=NULL)
    {
        //Ottengo informazioni sul contatto da stampare.
        Contact info = index->info;
        printf("Nome: %s Cognome: %s Numero di telefono: %s",info.name,info.surname,info.telephoneNumber);
        puts("");
        //Aggiorno il puntatore di scansione all'elemento successivo.
        index = index->nextPtr;
    }
    puts("");
    
}
//Funzione "loadContact()", necessaria al caricamento di un nuovo contatto, al fine di
//semplificare le operazioni di input nel main.
//La funzione riceve in ingresso un puntatore a contatto. 
void loadContact(Contact *contatto)
{
    printf("%s","Insert name: ");
    scanf("%19s",contatto->name);
    printf("%s","Insert surname: ");
    scanf("%19s",contatto->surname);
    printf("%s","Insert the telephone number: ");
    scanf("%19s",contatto->telephoneNumber);
    puts("");
}
//Funzione "instruction()" necessaria alla stampa del menù utente.
void instructions()
{
    puts("***Please, select an option***");
    puts("1.Add new contact.");
    puts("2.Delete a contact.");
    puts("3.Print the contact list.");
    puts("0.Exit.");
}
//------------------------------------------------------------------------------






