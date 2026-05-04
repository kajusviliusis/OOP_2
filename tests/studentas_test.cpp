#include "Studentas.h"

#include <gtest/gtest.h>

#include <sstream>
#include <string>
#include <utility>

namespace {

bool studentaiVienodi(const Studentas& a, const Studentas& b)
{
    return a.getVardas() == b.getVardas()
        && a.getPavarde() == b.getPavarde()
        && a.getEgz() == b.getEgz()
        && a.getNd() == b.getNd();
}

}

TEST(StudentasTest, DefaultConstructorSukuriaTusciaObjekta)
{
    Studentas s;

    EXPECT_TRUE(s.getVardas().empty());
    EXPECT_TRUE(s.getPavarde().empty());
    EXPECT_EQ(s.getEgz(), 0);
    EXPECT_TRUE(s.getNd().empty());
    EXPECT_DOUBLE_EQ(s.getGalVid(), 0.0);
    EXPECT_DOUBLE_EQ(s.getGalMed(), 0.0);
}

TEST(StudentasTest, CopyConstructorNukopijuojaVisusDuomenis)
{
    Studentas originalus("Jonas", "Jonaitis", 7, {8, 9});

    Studentas kopija(originalus);

    EXPECT_TRUE(studentaiVienodi(kopija, originalus));
}

TEST(StudentasTest, MoveConstructorPerkeliaDuomenis)
{
    Studentas originalus("Jonas", "Jonaitis", 7, {8, 9});

    Studentas perkeltas(std::move(originalus));

    EXPECT_EQ(perkeltas.getVardas(), "Jonas");
    EXPECT_EQ(perkeltas.getPavarde(), "Jonaitis");
    EXPECT_EQ(perkeltas.getEgz(), 7);
    ASSERT_EQ(perkeltas.getNd().size(), 2u);
    EXPECT_EQ(perkeltas.getNd()[0], 8);
    EXPECT_EQ(perkeltas.getNd()[1], 9);

    EXPECT_TRUE(originalus.getVardas().empty());
    EXPECT_TRUE(originalus.getPavarde().empty());
    EXPECT_EQ(originalus.getEgz(), 0);
    EXPECT_TRUE(originalus.getNd().empty());
}

TEST(StudentasTest, CopyAssignmentNukopijuojaVisusDuomenis)
{
    Studentas originalus("Petras", "Petraitis", 10, {6, 7});
    Studentas kopija;

    kopija = originalus;

    EXPECT_TRUE(studentaiVienodi(kopija, originalus));
}

TEST(StudentasTest, MoveAssignmentPerkeliaDuomenis)
{
    Studentas originalus("Tomas", "Tomaitis", 9, {10, 10});
    Studentas perkeltas;

    perkeltas = std::move(originalus);

    EXPECT_EQ(perkeltas.getVardas(), "Tomas");
    EXPECT_EQ(perkeltas.getPavarde(), "Tomaitis");
    EXPECT_EQ(perkeltas.getEgz(), 9);
    ASSERT_EQ(perkeltas.getNd().size(), 2u);
    EXPECT_EQ(perkeltas.getNd()[0], 10);
    EXPECT_EQ(perkeltas.getNd()[1], 10);

    EXPECT_TRUE(originalus.getVardas().empty());
    EXPECT_TRUE(originalus.getPavarde().empty());
    EXPECT_EQ(originalus.getEgz(), 0);
    EXPECT_TRUE(originalus.getNd().empty());
}

TEST(StudentasTest, DestruktoriusVeikiaTrinantPerBazinesKlasesRodykle)
{
    Zmogus* zmogus = new Studentas("Jonas", "Jonaitis", 10, {8, 9, 10});

    EXPECT_EQ(zmogus->tipas(), "Studentas");

    delete zmogus;
}

TEST(StudentasTest, InputOperatorNuskaitoDuomenisTeisingai)
{
    std::stringstream ivestis("Tomas Tomaitis 10 9 8 7\n");
    Studentas s;

    ivestis >> s;

    EXPECT_EQ(s.getVardas(), "Tomas");
    EXPECT_EQ(s.getPavarde(), "Tomaitis");
    EXPECT_EQ(s.getEgz(), 7);
    ASSERT_EQ(s.getNd().size(), 3u);
    EXPECT_EQ(s.getNd()[0], 10);
    EXPECT_EQ(s.getNd()[1], 9);
    EXPECT_EQ(s.getNd()[2], 8);
    EXPECT_DOUBLE_EQ(s.getGalVid(), 7.8);
    EXPECT_DOUBLE_EQ(s.getGalMed(), 7.8);
}

TEST(StudentasTest, OutputOperatorIsvedaDuomenisTeisingai)
{
    Studentas s("Tomas", "Tomaitis", 7, {10, 9, 8});
    std::stringstream isvestis;

    isvestis << s;

    EXPECT_EQ(isvestis.str(), "Tomas Tomaitis 10 9 8 7");
}

TEST(StudentasTest, SkaiciuotiGalutiniSuVidVeikiaTeisingai)
{
    Studentas s("Jonas", "Jonaitis", 10, {8, 9, 10});

    EXPECT_DOUBLE_EQ(s.skaiciuotiGalutiniSuVid(), 9.6);
}

TEST(StudentasTest, SkaiciuotiGalutiniSuMedVeikiaTeisingai)
{
    Studentas s("Jonas", "Jonaitis", 10, {8, 9, 10});

    EXPECT_DOUBLE_EQ(s.skaiciuotiGalutiniSuMed(), 9.6);
}
