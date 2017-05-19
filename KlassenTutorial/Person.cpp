#include "Person.h"

#include <iostream>
using std::cout;
using std::endl;

Person::Person(string name, Gender gender, Haircolor haircolor, int age, Language language) {
    this->name = name;
    this->gender = gender;
    this->haircolor = haircolor;
    this->age = age;
    this->language;
}

void Person::introduce() {
    // Achtung!: Vorturteilbelastet
    int displayedAge = age;
    if (gender == Gender::Female) {
        if (age > 14 && age < 18) displayedAge = 18;
        if (age > 18 && age - 10 < 18) displayedAge -= 10;
    }

    if (language == Language::German) {
        cout << "Hallo ich bin " << name << ". Ich bin " << displayedAge << " jahre alt." << endl;
    }
    else if (language == Language::Enlish) {
        cout << "Hi, I am " << name << ". I am " << displayedAge << " years old." << endl;
    }
}

void Person::greet(Person &person) {
    if (language == Language::German) {
        cout << "Hallo " << person.getName() << ", ich bin " << name << endl;
    }
    else if (language == Language::Enlish) {
        cout << "Hi " << person.getName() << ", I am " << name << endl;
    }
}