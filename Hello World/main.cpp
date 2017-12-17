//  Exercices tirés de "Programming"
// Created by André Tonic on 17/11/2017.
// Dernier cours : 17/12/2017

// Headers générés naturellement par Xcode
// #include <iostream>
// #include <math.h>

// Caractères spéciaux : [ ]   '\n'   {  }   ||    Bool : 0 Faux 1 Vrai
// CTRL D termine la saisie dans cin


// Version initiale du Book de BS
#include "std_lib_facilities.h"

// *****************************************************************************************************
// Exo 6 - page 219 = implémentation d'une grammaire anglaise très simple
// *****************************************************************************************************

class Mot_type {                      // Création d'un nouveau type composé de deux membres
public:
    string mot;
    int type;                          // 0 = indéfini, 1 = nom   2 = verbe   3 = conjonction
    Mot_type(string ch, int val)     // On crée une nouvelle occurence
    :mot(ch), type(val) { }
};



// -----------------------------------------------------------------------------------------------------
int main()
{

    // Initialisation de la grammaire
    vector<string>noms={"birds", "fish", "C++"};
    vector<string>verbes={"rules", "fly", "swim"};
    vector<string>conjonctions={"and", "or", "but"};
    
    string mot="";
    vector<Mot_type>mots;
    
    cout << "Saisissez votre phrase dont la syntaxe sera vérifiée <. pour terminer la saisie> :\n";
    
    while (cin){
        cin >> mot;
        if (mot==".")break;
        else mots.push_back(Mot_type(mot,0)); // On pushe 0 car le type du mot est indéfini à ce stade
        
    }

    for (int i=0;i<mots.size();i++){
        // On affecte un type (1, 2, 3) à chaque mot saisi en balayant les 3 vecteurs prédéfinis : noms, verbes, conjonctions
        for (int j=0;j<noms.size();j++)
            if (mots[i].mot==noms[j])mots[i].type=1;
        for (int j=0;j<verbes.size();j++)
            if (mots[i].mot==verbes[j])mots[i].type=2;
        for (int j=0;j<conjonctions.size();j++)
            if (mots[i].mot==conjonctions[j])mots[i].type=3;
        
        // Affichage
        cout << mots[i].mot << " "<< mots[i].type <<'\n';
        
    }
    
    // On vérifie la grammaire qui doit suivre la régle "nom verbe conjonction" (1, 2, 3)
    // Ex : birds fly = OK / birds fly but = NOK / birds fly but birds = NOK / birds fly but fish swim = OK
    bool phrase_valide=false;
    bool new_phrase_attendue=false;
    
    int rang_seq=1;
    
    for (int i=0;i<mots.size();i++){
        if (mots[i].type==rang_seq){
            
            phrase_valide=true; // Si le type du mot est bien égal au rang de la séquence (nom verbe conjonction), on est OK !
            rang_seq++;         // on avance dans la séquence
            
            if (rang_seq==3){
                new_phrase_attendue=false; // La phrase est complète (nom+verbe)
            }
            
            if (rang_seq==4){                   // Quand on atteint la conjonction tous les 3 mots, on attend une nouvelle phrase
                new_phrase_attendue=true;
                rang_seq=1;               // On repart au début de la séquence
                }
            
            }
        else
            {
            phrase_valide=false;
            break;
        }
    }
    
    // On affiche le résultat si la phrase est valide et que l'on n'attend pas une nouvelle phrase post-conjonction
    if (phrase_valide&&!new_phrase_attendue)cout<<"La phrase saisie est OK !\n";
    else cout<<"La phrase saisie n'est pas conforme !\n";
    
    
}
// ************************************************************************************************************





/* ARCHIVES
// *****************************************************************************************************
// Exo 4 - page 218 = nouvelle version de l'exercice 19 - Chap 4 - page 130 - Création d'une class Name
// *****************************************************************************************************

class Name_value {                      // Création d'un nouveau type composé de deux membres
public:
    string name;
    int value;
    Name_value(string ch, int val)     // On crée une nouvelle occurence
    :name(ch), value(val) { }
};


class Name_value_exist{ // On crée une classe avec une seule méthode qui permet de vérifier l'existence d'une occurence dans un vecteur
public:
    bool exist(vector<Name_value> p, string n, int v);
};

Name_value_exist e; // On fournit la méthode exist

bool Name_value_exist::exist(vector<Name_value> p, string n, int v) // Définition de la méthode exist
{
    // On balaye le vecteur pour vérifier
    for (Name_value x:p)
        if (x.name==n&&x.value==v)return 1; // la paire existe déjà
    return 0; // la paire n'existe pas
}


// -----------------------------------------------------------------------------------------------------
int main()
{
    
    vector<Name_value> paire; // Création du vecteur avec la classe définie plus haut
    string nom="";
    int valeur=0;
    
    while (cin) {
        
        cout << "Saisir une paire (nom valeur) - NoName 0 permet de stopper la saisie :\n";
        cin >>nom>>valeur;
        if (nom=="NoName"&&valeur==0)break;
        
        // Vérification que cette nouvelle paire saisie n'a pas DEJA été saisie
        if (e.exist(paire,nom,valeur)) {
            cout << "Cette paire a déjà été saisie. Veuillez recommencer\n";
        } else {
            // Si ce n'est pas le cas, on push
            paire.push_back(Name_value(nom,valeur));
        }
        
    }
    
    // Affichage de toutes les paires saisies en balayant le vecteur après un tri
    // Attention : le tri sort(paire) ne fonctionne pas - Il faudra vérifier plus tard quelle syntaxe de tri sur un vecteur construit autour d'un type particulier (nom, valeur)
    cout << "Le vecteur comprend "<<paire.size()<<" éléments\n";
    for (Name_value x:paire)
        cout << x.name << " - "<<x.value<<'\n';
    
}
// ************************************************************************************************************
*/
