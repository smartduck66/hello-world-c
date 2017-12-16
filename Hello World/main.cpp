//  Exercices tirés de "Programming"
// Created by André Tonic on 17/11/2017.
// Dernier cours : 09/12/2017

// Headers générés naturellement par Xcode
// #include <iostream>
// #include <math.h>

// Caractères spéciaux : [ ]   '\n'   {  }   ||

// Nouvelle version de l'exercice 19 - Chap 4 - page 130 - Création d'une class Name


// Version initiale du Book de BS
#include "std_lib_facilities.h"


// -----------------------------------------------------------------------------------------------------
// Exo 4 - page 218 = nouvelle version de l'exercice 19 - Chap 4 - page 130 - Création d'une class Name
// -----------------------------------------------------------------------------------------------------

class Name_value {
public:
    string name;
    int value;
    Name_value(string ch, int val)     // On crée une nouvelle occurence
    :name(ch), value(val) { }
};


int main()
{

    vector<Name_value> paire;
    string nom="";
    int valeur=0;
    
    while (cin) {
    
        cout << "Saisir une paire (nom valeur) - NoName 0 permet de stopper la saisie :\n";
        cin >>nom>>valeur;
        if (nom=="NoName"&&valeur==0)break;
        
        // Vérification que cette nouvelle paire saisie n'a pas DEJA été saisie
        if (ExistePaire) {
            cout << "Cette paire a déjà été saisie. Veuillez recommencer\n";
        } else {
            // Si ce n'est pas le cas, on push
            Name_value(nom,valeur);
        }
    
    }
    
    // Affichage de toutes les paires saisies en balayant le vecteur
    for (Name_value x:paire)
        cout << x.name << " - "<<x.value<<'\n';
        
}
// ************************************************************************************************************

