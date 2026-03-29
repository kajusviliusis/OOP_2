#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    int egz_;
    std::vector<int> nd_;
    double galVid_;
    double galMed_;

public:
    const std::string& getVardas() const { return vardas_; }
    const std::string& getPavarde() const { return pavarde_; }
    int getEgz() const { return egz_; }
    const std::vector<int>& getNd() const { return nd_; }
    double getGalVid() const { return galVid_; }
    double getGalMed() const { return galMed_; }

    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }
    void setEgz(int e) { egz_ = e; }
    void setGalVid(double v) { galVid_ = v; }
    void setGalMed(double v) { galMed_ = v; }

    double skaiciuotiGalutiniSuVid() const;
    double skaiciuotiGalutiniSuMed() const;
};

#endif

