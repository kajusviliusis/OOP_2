#include "Studentas.h"

#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

static_assert(std::is_abstract<Zmogus>::value, "Zmogus turi buti abstrakti klase");

bool studentaiVienodi(const Studentas& a, const Studentas& b)
{
    return a.getVardas() == b.getVardas()
        && a.getPavarde() == b.getPavarde()
        && a.getEgz() == b.getEgz()
        && a.getNd() == b.getNd();
}

void testDefaultConstructor()
{
    Studentas s;

    assert(s.getVardas().empty());
    assert(s.getPavarde().empty());
    assert(s.getEgz() == 0);
    assert(s.getNd().empty());

    std::cout << "Default konstruktorius praejo.\n";
}

void testCopyConstructor()
{
    Studentas originalus("Jonas", "Jonaitis", 7, {8, 9});

    Studentas kopija(originalus);

    assert(studentaiVienodi(kopija, originalus));

    std::cout << "Copy konstruktorius praejo.\n";
}

void testMoveConstructor()
{
    Studentas originalus("Jonas", "Jonaitis", 7, {8, 9});

    Studentas perkeltas(std::move(originalus));

    assert(perkeltas.getVardas() == "Jonas");
    assert(perkeltas.getPavarde() == "Jonaitis");
    assert(perkeltas.getEgz() == 7);
    assert(perkeltas.getNd().size() == 2);
    assert(perkeltas.getNd()[0] == 8);
    assert(perkeltas.getNd()[1] == 9);


    assert(originalus.getEgz() == 0);
    assert(originalus.getVardas() == "");
    assert(originalus.getNd().size() == 0);
    assert(originalus.getPavarde() == "");

    std::cout << "Move konstruktorius praejo.\n";
}

void testCopyAssignment()
{
    Studentas originalus("Petras", "Petraitis", 10, {6, 7});

    Studentas kopija;
    kopija = originalus;

    assert(studentaiVienodi(kopija, originalus));

    std::cout << "Copy assignment operatorius praejo.\n";
}

void testMoveAssignment()
{
    Studentas originalus("Tomas", "Tomaitis", 9, {10, 10});

    Studentas perkeltas;
    perkeltas = std::move(originalus);

    assert(perkeltas.getVardas() == "Tomas");
    assert(perkeltas.getPavarde() == "Tomaitis");
    assert(perkeltas.getEgz() == 9);
    assert(perkeltas.getNd().size() == 2);
    assert(perkeltas.getNd()[0] == 10);
    assert(perkeltas.getNd()[1] == 10);

    assert(originalus.getEgz() == 0);
    assert(originalus.getVardas() == "");
    assert(originalus.getNd().size() == 0);
    assert(originalus.getPavarde() == "");

    std::cout << "Perkelimo priskyrimo operatorius praejo.\n";
}

void testInputOutputOperators()
{
    std::stringstream ivestis("Tomas Tomaitis 10 9 8 7\n");
    Studentas s;

    ivestis >> s;

    assert(s.getVardas() == "Tomas");
    assert(s.getPavarde() == "Tomaitis");
    assert(s.getEgz() == 7);
    assert(s.getNd().size() == 3);
    assert(s.getNd()[0] == 10);
    assert(s.getNd()[1] == 9);
    assert(s.getNd()[2] == 8);

    std::stringstream isvestis;
    isvestis << s;

    assert(isvestis.str() == "Tomas Tomaitis 10 9 8 7");

    std::cout << "I/O operatoriai praejo.\n";
}

void testDestructor()
{
    for (int i = 0; i < 1000; ++i) {
        Studentas laikinas("A","B",1,{1});
    }

    std::cout << "Destruktoriaus netiesioginis testas praejo.\n";
}

int main()
{

    // Zmogus zmogus("Vardas", "Pavarde");
    //error: cannot declare variable ‘zmogus’ to be of abstract type ‘Zmogus’
    //note: because the following virtual functions are pure within ‘Zmogus’:
    //note: ‘virtual std::string Zmogus::tipas() const’

    try {
        testDefaultConstructor();
        testCopyConstructor();
        testMoveConstructor();
        testCopyAssignment();
        testMoveAssignment();
        testInputOutputOperators();
        testDestructor();

        std::cout << "\nVisi testai atlikti sekmingai.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Testuose ivyko klaida: " << e.what() << '\n';
    }
}