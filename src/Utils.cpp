#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Utils.hpp"
#include <iomanip>

using namespace std;

double CalcolaInteressi(const double& S, const size_t& n, const double* const& w, const double* const& r) {
    double V = 0.0;
    for (unsigned int i = 0; i < n; ++i) {
        double temp = r[i] + 1.0;
        V += S * w[i] * temp;
    }
    return V;
}

bool EsportaRisultato(const string& file_name, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& V)
{
    ofstream outputFile(file_name);

    if (!outputFile.is_open())
    {
        cerr << "Errore: impossibile scrivere su file!" << endl;
        return false;
    }

    outputFile << fixed << setprecision(2);
    outputFile << "S = " << S << ", n = " << n << endl;

    outputFile << defaultfloat << setprecision(6);
    outputFile << "w = [ ";
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) outputFile << " ";
        outputFile << w[i];
    }
    outputFile << " ]" << endl;

    outputFile << "r = [";
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) outputFile << " ";
        outputFile << r[i];
    }
    outputFile << "]" << endl;

    double rendimento = (V - S) / S;
    outputFile << "Rate of return of the portfolio: " << rendimento << endl;

    outputFile << fixed << setprecision(2) << "V: " << V << endl;

    outputFile.close();
    return true;
}

bool ImportData(const string& file_name, double& S, size_t& n, double*& w, double*& r) {
    ifstream inputFile(file_name);
    if (!inputFile.is_open()) {
        cerr << "Errore: file non trovato!" << endl;
        return false;
    }

    string linea;
    getline(inputFile, linea);
    S = stod(linea.substr(2));

    getline(inputFile, linea);
    n = stoi(linea.substr(2));

    getline(inputFile, linea); // riga vuota o intestazione

    w = new double[n];
    r = new double[n];

    for (size_t i = 0; i < n; ++i) {
        getline(inputFile, linea);
        size_t sep = linea.find(';');

        string w_str = linea.substr(0, sep);
        string r_str = linea.substr(sep + 1);

        w[i] = stod(w_str);
        r[i] = stod(r_str);
    }

    inputFile.close();
    return true;
}