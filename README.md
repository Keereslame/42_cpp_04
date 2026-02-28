# C++ Module 04 --- Subtype Polymorphism, Abstract Classes & Interfaces

> **Objectif :** Comprendre et maîtriser le polymorphisme en C++98, les
> classes abstraites, les interfaces simulées et la gestion mémoire
> avancée.

------------------------------------------------------------------------

## Table des matières

1.  [Le polymorphisme](#1-le-polymorphisme)
2.  [Les fonctions virtuelles](#2-les-fonctions-virtuelles)
3.  [Le destructeur virtuel](#3-le-destructeur-virtuel)
4.  [WrongAnimal vs Animal (erreur
    classique)](#4-wronganimal-vs-animal-erreur-classique)
5.  [Allocation dynamique & gestion
    mémoire](#5-allocation-dynamique--gestion-mémoire)
6.  [Deep Copy vs Shallow Copy](#6-deep-copy-vs-shallow-copy)
7.  [La forme canonique orthodoxe
    (OCF)](#7-la-forme-canonique-orthodoxe-ocf)
8.  [Les classes abstraites](#8-les-classes-abstraites)
9.  [Les interfaces en C++98](#9-les-interfaces-en-c98)
10. [Le Prototype Pattern (clone)](#10-le-prototype-pattern-clone)
11. [Le Factory Pattern
    (MateriaSource)](#11-le-factory-pattern-materiasource)
12. [Gestion d'inventaire & responsabilité
    mémoire](#12-gestion-dinventaire--responsabilité-mémoire)
13. [Récapitulatif par exercice](#13-récapitulatif-par-exercice)

------------------------------------------------------------------------

## 1. Le polymorphisme

Le **polymorphisme** permet d'utiliser une classe dérivée via un
pointeur ou une référence vers sa classe de base.

``` cpp
Animal* a = new Dog();
a->makeSound(); // comportement dépend du type réel si virtual
```

Deux notions importantes :

-   **Type statique** : type déclaré (Animal\*)
-   **Type dynamique** : type réel de l'objet (Dog)

Le polymorphisme dynamique fonctionne uniquement avec des **fonctions
virtuelles**.

------------------------------------------------------------------------

## 2. Les fonctions virtuelles

Une fonction virtuelle permet une résolution dynamique à l'exécution.

``` cpp
class Animal {
public:
    virtual void makeSound() const;
};
```

Sans `virtual`, la méthode appelée dépend du **type statique**. Avec
`virtual`, elle dépend du **type dynamique**.

------------------------------------------------------------------------

## 3. Le destructeur virtuel

Toute classe destinée à être héritée doit avoir un destructeur virtuel.

``` cpp
virtual ~Animal();
```

Pourquoi ?

``` cpp
Animal* a = new Dog();
delete a; // comportement incorrect sans destructeur virtuel
```

Sans destructeur virtuel → destruction incomplète → fuite mémoire.

------------------------------------------------------------------------

## 4. WrongAnimal vs Animal (erreur classique)

Si une méthode n'est pas virtuelle :

``` cpp
WrongAnimal* a = new WrongCat();
a->makeSound(); // appelle WrongAnimal::makeSound()
```

Le polymorphisme ne fonctionne pas.

Cette partie du module sert à démontrer pourquoi `virtual` est
indispensable.

------------------------------------------------------------------------

## 5. Allocation dynamique & gestion mémoire

Exemple avec Brain :

``` cpp
Brain* brain = new Brain();
```

Règle fondamentale :

> Chaque `new` doit avoir un `delete`.

Tester avec :

``` bash
valgrind ./a.out
```

Objectif : zéro memory leak.

------------------------------------------------------------------------

## 6. Deep Copy vs Shallow Copy

### Shallow Copy (interdit ici)

``` cpp
this->brain = other.brain;
```

Problèmes : - Double delete - Partage mémoire involontaire

### Deep Copy (obligatoire)

``` cpp
this->brain = new Brain(*other.brain);
```

Chaque objet possède sa propre mémoire.

------------------------------------------------------------------------

## 7. La forme canonique orthodoxe (OCF)

Toute classe doit implémenter :

``` cpp
class MyClass {
public:
    MyClass();
    MyClass(const MyClass& other);
    MyClass& operator=(const MyClass& other);
    ~MyClass();
};
```

Particulièrement important quand la classe possède :

-   Des pointeurs
-   Des ressources dynamiques

------------------------------------------------------------------------

## 8. Les classes abstraites

Une classe devient abstraite si elle contient au moins une fonction
virtuelle pure.

``` cpp
virtual void makeSound() const = 0;
```

Conséquence :

``` cpp
Animal a; // interdit
```

Mais :

``` cpp
Animal* a = new Dog(); // autorisé
```

But : empêcher l'instanciation d'une classe conceptuelle.

------------------------------------------------------------------------

## 9. Les interfaces en C++98

C++98 ne possède pas le mot-clé `interface`.

On simule une interface via une **classe abstraite pure** :

``` cpp
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria*) = 0;
    virtual void unequip(int) = 0;
    virtual void use(int, ICharacter&) = 0;
};
```

Caractéristiques : - Uniquement des fonctions virtuelles pures - Aucun
attribut - Destructeur virtuel

------------------------------------------------------------------------

## 10. Le Prototype Pattern (clone)

Dans `AMateria` :

``` cpp
virtual AMateria* clone() const = 0;
```

Chaque classe concrète retourne une copie d'elle-même.

``` cpp
AMateria* Ice::clone() const {
    return new Ice(*this);
}
```

Permet la création dynamique sans connaître le type exact.

------------------------------------------------------------------------

## 11. Le Factory Pattern (MateriaSource)

`MateriaSource` apprend des modèles puis les reproduit.

``` cpp
AMateria* createMateria(std::string const& type);
```

Fonctionnement : 1. learnMateria() stocke un prototype 2.
createMateria() clone le prototype correspondant

Si type inconnu → retourne 0

------------------------------------------------------------------------

## 12. Gestion d'inventaire & responsabilité mémoire

Le `Character` possède :

-   4 slots maximum
-   `equip()` ajoute si slot libre
-   `unequip()` NE delete PAS
-   `use()` appelle la Materia correspondante

Règle importante :

> Celui qui alloue est responsable de libérer.

Éviter : - Double delete - Dangling pointers - Memory leaks

------------------------------------------------------------------------

## 13. Récapitulatif par exercice

  -----------------------------------------------------------------------
  Exercice                      Concepts clés
  ----------------------------- -----------------------------------------
  **ex00**                      Polymorphisme, virtual, destructeur
                                virtuel, différence type
                                statique/dynamique

  **ex01**                      Allocation dynamique, Brain, deep copy,
                                OCF

  **ex02**                      Classe abstraite, fonction virtuelle pure

  **ex03**                      Interfaces, clone(), Factory pattern,
                                gestion d'inventaire, responsabilité
                                mémoire
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Commande de compilation

``` bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

------------------------------------------------------------------------

## Conclusion

Le Module 04 est un tournant majeur dans l'apprentissage du C++.

Il introduit : - Le vrai polymorphisme - La conception orientée objet
robuste - Les bases des design patterns - La gestion mémoire avancée

Maîtriser ce module signifie comprendre réellement comment fonctionne la
POO en C++98.
