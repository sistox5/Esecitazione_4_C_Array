#pragma once

#include <iostream>
using namespace std;

bool EsportaRisultato(const string& file_name, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& V);

double CalcolaInteressi(const double& s, const size_t& n, const double* const& w, const double* const& v);

bool ImportData(const string& file_name, double& S, size_t& n, double*& w, double*& r);