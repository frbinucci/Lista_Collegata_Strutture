/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utilities.h
 * Author: franc
 *
 * Created on 12 agosto 2017, 14.00
 * File contenente la dichiarazione dei prototipi e delle strutture necessarie
 * alla gestione di una lista collegata che rappresenta un elenco telefonico.
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#ifdef __cplusplus
extern "C" {
#endif

#include<stdbool.h>
/*Definizione della struttura "s_contact". Questa consente la memorizzazione
 * di un preciso contatto telefonico. 
 * Un contatto telefonico è rappresentato da tre campi:
 *    char name[20] => Campo che rappresenta il nome del contatto.
 *    char surname[20] => Campo che rappresenta il cognome del contatto.
 *   char telephoneNumber[20] => Campo che rappresenta il numero di telefono del contatto.*/
struct s_contact{
    char name[20];
    char surname[20];
    char telephoneNumber[20];
};

//Definizione alias.
typedef struct s_contact Contact;

//Definizione della struttura "s_nodo".
//Tale struttura rappresenta un nodo per la lista collegata.
struct s_nodo{
    //Parte relativa alle informazioni.
    Contact info;
    //Puntatore al nodo successivo.
    struct s_nodo *nextPtr;
};

//Definizione degli alias.
typedef struct s_nodo Nodo;
typedef Nodo* nodePtr;

//------------------------------------------------------------------------------
//----------------DEFINIZIONE DEI PROTOTIPI DELLE FUNZIONI NECESSARIE-----------
/*Funzione necessaria all'inserimento di un nuovo contatto nell'elenco.
 * La funzione riceve in ingresso 2 parametri:
 * nodePtr list => Parametro di tipo puntatore a nodo, che rappresenta la lista.
 * Contatto value => Valore da inserire.*/
bool insert(nodePtr *list,Contact newContact);
/*Funzione necessaria alla rimozione di un contatto dall'elenco.
 * La funzione riceve in ingresso 2 parametri:
 * nodePtr *list => Parametro di tipo puntatore a puntatore nodo, che rappresenta la lista.
 * (Il puntatore a nodo è passato per riferimento poiché si ha la necessità di modificarne il valore
 * nel caso in cui si debbano eseguire operazioni sul primo elemento della lista).
 * char number[] => Array di char che rappresenta il numero di telefono del contatto
 * da eliminare.
 */
bool deleteByNumber(nodePtr *list,char number[]);
/*Funzione necessaria a controllare se la lista contatti sia vuota o meno.
 * La funzione riceve in ingresso un parametro: 
 * nodePtr *list => Parametro di tipo puntatore a puntatore a nodo, che rappresenta la lista.
 * (Il puntatore a nodo è passato per riferimento poiché si ha la necessità di modificarne il valore
 * nel caso in cui si debbano eseguire operazioni sul primo elemento della lista).
 * La funzione restituisce "true" (1) se la lista è vuota e "false" (0) se è piena.*/
bool isEmpty(nodePtr list);
/*Funzione necessaria alla stampa della lista.
 * La funzione riceve in ingresso un parametro: 
 * nodePtr list => Parametro di tipo puntatore a nodo, che rappresenta la lista.*/
void printList(nodePtr list);
/*Funzione necessaria al caricamento delle informazioni relative ad un determinato contatto.
 * La funzione riceve in ingresso un parametro:
 * Contatto *newContatto => Parametro di tipo puntatore a Contatto, rappresentante il contatto
 * da caricare.*/
void loadContact(Contact *newContact);
//Funzione necessaria alla stampa del menù.
void instructions();
//------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif /* UTILITIES_H */

