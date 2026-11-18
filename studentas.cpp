#include "studentas.h"
#include <sstream>
#include <stdexcept>
#include <utility>

studentas::studentas() : egzaminas_(0){}

studentas::studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& namudarbai, int egzaminas):
    vardas_(vardas),
      pavarde_(pavarde),
      namudarbai_(namudarbai),
      egzaminas_(egzaminas){}

studentas::studentas(std::istream& is) : egzaminas_(0){
    readStudent(is);
}
studentas::~studentas() = default;
const std::string& studentas::vardas() const{
    return vardas_;
}
const std::string& studentas::pavarde() const {
    return pavarde_;
}

const std::vector<int>& studentas::namudarbai() const{
    return namudarbai_;
}

int studentas::egzaminas() const{
    return egzaminas_;
}

void studentas::setVardas(const std::string& vardas){
    vardas_ = vardas;
}

void studentas::setPavarde(const std::string& pavarde) {
    pavarde_ = pavarde;
}

void studentas::setNamudarbai(const std::vector<int>& namudarbai){
    for (int pazymys : namudarbai){
        if (pazymys < 1 || pazymys > 10){
            throw std::invalid_argument("Netinkamas namu darbu pazymys");
        }
    }
    namudarbai_ = namudarbai;
}

void studentas::setEgzaminas(int egzaminas){
    if (egzaminas < 1 || egzaminas > 10){
        throw std::invalid_argument("Netinkamas egzamino pazymys");
    }
    egzaminas_ = egzaminas;
}

double studentas::galutinisVidurkis() const {
    if (namudarbai_.empty()){
        return 0.6 * egzaminas_;
    }

    double suma = 0.0;

    for (int pazymys : namudarbai_){
        suma += pazymys;
    }

    double vidurkis = suma / namudarbai_.size();

    return 0.4 * vidurkis + 0.6 * egzaminas_;
}

std::istream& studentas::readStudent(std::istream& is){
    std::string eilute;

    if (!std::getline(is >> std::ws, eilute)){
        return is;
    }

    std::istringstream srautas(eilute);
    std::string pavarde;
    std::string vardas;

    if (!(srautas >> pavarde >> vardas)){
        is.setstate(std::ios::failbit);
        return is;
    }
    std::vector<int> pazymiai;
    int pazymys;

    while (srautas >> pazymys){
        pazymiai.push_back(pazymys);
    }
    if (!srautas.eof() || pazymiai.size() < 2){
        is.setstate(std::ios::failbit);
        return is;
    }
    for (int p : pazymiai){
        if (p < 1 || p > 10) {
            is.setstate(std::ios::failbit);
            return is;
    }
    }
    int egzaminas = pazymiai.back();
    pazymiai.pop_back();
    vardas_ = std::move(vardas);
    pavarde_ = std::move(pavarde);
    namudarbai_ = std::move(pazymiai);
    egzaminas_ = egzaminas;

    return is;
}
