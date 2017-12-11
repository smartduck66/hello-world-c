//  Crible d'Erastothene : détermination des nombres premiers
//  Created by André Tonic on 17/11/2017.

// Caractères spéciaux : [ ]   '\n'   {  }   ||


// Version initiale du Book de BS
#include "std_lib_facilities.h"

vector<double> crible_erasthotene(double x)
{
    // En entrée : un nombre définissant la limite maximale de recherche des nombres premiers (ex : 1000)
    // En sortie : un vecteur composé de nombres représentant la table des nombres premiers déterminés
    // Intérêt de cet algorithme : sa vélocité sur une recherche large (ex : entre 1 et 10 000 000)
    
    // On remplit la table
    vector<double>table;
    for (double i=0;i<=x;++i)table.push_back(i);
    table[1]=0; // On supprime 1 qui n'est pas premier (1 seul diviseur distinct)
    
    
    //On supprime chaque multiple des entiers de la table
    for (double i=2;i<=x;++i)
    {
        double j=2;
        
        // On supprime les multiples de l'entier i en balayant la table avec le pointeur j
        while (i*j<=x) {
            
            table[i*j]=0;
            ++j;
        }
        
    }
    
    // On renvoit la table épurée des multiples
    return table;
}



int main()
{
    
    vector<double> primes;
    double limite_max=0.0;
    double total_primes=0.0;
    
    cout << "Saisissez la limite maximale de recherche des nombres premiers : \n";
    cin >> limite_max;
    
    primes=crible_erasthotene(limite_max);
    
    for (int x:primes)
    {
        if (x>0)
        {
            cout <<x<<'\n';
            ++total_primes;
            
        }
        
    }
    
    
    cout << "Le nombre total de nombres premiers entre 1 et la limite saisie est de "<<total_primes<<'\n';
    
    
}
