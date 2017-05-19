#include <iostream>
#include "Person.h"

int main() {
    Person kevin("Kevin", Gender::Male, Haircolor::Black, 18, Language::German);
    Person jaqueline("Jaqueline", Gender::Female, Haircolor::Blond, 17, Language::Enlish);

    kevin.introduce();
    jaqueline.introduce();

    kevin.greet(jaqueline);
    jaqueline.greet(kevin);
}