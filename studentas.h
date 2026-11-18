#ifndef STUDENTAS_H
#define STUDENTAS_H
#include <string>
#include <vector>
#include <iostream>

class studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> namudarbai_;
    int egzaminas_;

public:
    studentas();
    studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& namudarbai, int egzaminas);
    explicit studentas(std::istream& is);

    studentas(const studentas&) = default;
    studentas(studentas&&) = default;
    studentas& operator=(const studentas&) = default;
    studentas& operator=(studentas&&) = default;

    ~studentas();
    const std::string& vardas() const;
    const std::string& pavarde() const;
    const std::vector<int>& namudarbai() const;
    int egzaminas() const;

    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setNamudarbai(const std::vector<int>& namudarbai);
    void setEgzaminas(int egzaminas);
    double galutinisVidurkis() const;
    std::istream& readStudent(std::istream& is);
};
#endif
