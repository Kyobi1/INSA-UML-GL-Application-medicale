#pragma once
// Empreinte.h
#include <string>
#include <list>
#include <vector>
#include "Attribut.h"
#include "AttributString.h"
#include "stdafx.h"


#ifndef Empreinte_H
#define Empreinte_H

using namespace std;

class Empreinte
{
	protected:
		int NoID;
		vector<Attribut*> listeAttributs;
		static const string FICHIER_EMPREINTES;
		static const string FICHIER_METADONNEES;
		static vector<int> modele;

	public:
		Empreinte();

		Empreinte(int id, list<Attribut*> liste);

		~Empreinte();

		double distance(Empreinte e);
		void sauvegarderEmpreinte();
};

#endif
