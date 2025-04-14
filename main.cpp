#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string file_name = "./data.txt";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double V = 0;

    bool ok = ImportData(file_name, S, n, w, r);
    if (!ok)
    {
        cerr << "Errore durante l'importazione dei dati." << endl;
        return -1;
    }
    cout << "Dati letti correttamente." << endl;

    V = CalcolaInteressi(S, n, w, r);

    string outputFileName = "./result.txt";
    bool done = EsportaRisultato(outputFileName, S, n, w, r, V);
    if (!done)
    {
        cerr << "Problema nella scrittura del file di output." << endl;
        return -1;
    }
    cout << "Scrittura completata con successo." << endl;

    delete[] w;
    delete[] r;

    return 0;
}