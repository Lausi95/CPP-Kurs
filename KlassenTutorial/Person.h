//
// Created by tom on 19.05.17.
//

#ifndef KLASSENTUTORIAL_PERSON_H
#define KLASSENTUTORIAL_PERSON_H

#include <string>
using std::string;

enum class Gender {
    Male,
    Female
};

enum class Haircolor {
    Blond,
    Black,
    Red,
    Gray,
    Brown
};

enum class Language {
    German,
    Enlish
};

class Person {
public:
    // Konstruktor
    Person(string, Gender, Haircolor, int, Language);

    // funktionen
    void introduce();
    void greet(Person &person);

    // gibt den namen zurück DA DA DAAAAAAA!
    inline string getName() { return name; }
private:
    string name;
    Gender gender;
    Haircolor haircolor;
    int age; // better: date of birth
    Language language;
};

#endif //KLASSENTUTORIAL_PERSON_H
