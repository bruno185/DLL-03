// DLL-03.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
/*
**************************************************************************************
Pour Créer une solution avec une applicaion qui appelle une DLL écite en assembleur   *
**************************************************************************************
Il faut :
- Créer l'application appelante (par exemple : DLL-03)  en C++
- Créer un autre projet DANS la solution, pour la DLL la DLL
- Mettre MASM dans "Dépedance de build / personnalisation de la build
- Ecrire le code en assembleur
- Ecrire la fonction :
        _DllMainCRTStartup proc h:QWORD, r:DWORD, u:QWORD
            mov rax, 1 ; ???
            ret
        _DllMainCRTStartup endp
- Ecrire les autres fonctions
- Créer un fichier .def pour EXPORTER les fonctions de la DLL
    par exemple :
    LIBRARY
    EXPORTS
    mafonction
    DoMul
- Dans l'application applante indiquer extern "C" suivi de la définition de la fonction de la DLL
- Faire cela pour toute les fonction de la DLL
- Utiliser les fonctions dans le code C++
- Créer une référence au projet DLL dans le projet de l'application appelante (sinon, erreur de link)
- Dans les propriétés de la solution, indiquer "Projet de démarrage unique, avec l'applicain appelante en paramètre

*/

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "Header.h";

extern "C" long long mafonction(long long i);
extern "C" int DoMul(int i, int j);



int main(void)
{
    std::cout << "Hello World!\n";

    long long l = mafonction(1234605616436508552);
    std::cout << "Ma fonction renvoie :" << std::hex << l << std::endl;

    int i = DoMul(16, 16);
    std::cout << "DoMul renvoie :" << std::dec<< i <<std::endl;

     
    /*
    HINSTANCE hinst = LoadLibraryA("DLL.dll");
    typedef long long (*FNPTR)(long long);
    FNPTR myfunc = (FNPTR)GetProcAddress(hinst, "mafonction");
    if (!myfunc) {
        std::cout << "Erreur !";
    }
    else 
    std::cout << myfunc(123456);
    */
}


