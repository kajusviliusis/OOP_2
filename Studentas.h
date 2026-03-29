#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <stdexcept>
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
    Studentas() : egz_(0), galVid_(0.0), galMed_(0.0) {}
    Studentas(const std::string& vardas, const std::string& pavarde)
       : vardas_(vardas), pavarde_(pavarde), egz_(0), galVid_(0.0), galMed_(0.0) {}
    ~Studentas() {}

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

    void pridetiNd(int pazymys) { nd_.push_back(pazymys); }
    void pasalintiPaskutiniNd() {
        if (nd_.empty()) throw std::runtime_error("Truksta pazymiu eiluteje");
        nd_.pop_back();
    }


    double skaiciuotiGalutiniSuVid() const;
    double skaiciuotiGalutiniSuMed() const;
};

#endif

