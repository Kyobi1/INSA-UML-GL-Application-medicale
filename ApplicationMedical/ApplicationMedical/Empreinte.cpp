#include "Empreinte.h"
#include <fstream>

using namespace std;

const string Empreinte::FICHIER_METADONNEES = "Metadonnees.txt";
const string Empreinte::FICHIER_EMPREINTES = "Empreintes.txt";
vector<int> Empreinte::modele;
vector<string> Empreinte::nomAttribut;

Empreinte::Empreinte()
{
	cout << "Construction d'une empreinte" << endl;
}

Empreinte::Empreinte(int id, vector<Attribut *> liste) : listeAttributs(liste)
{
	cout << "Construction de  l'empreinte : " << id << endl;
	NoID = id;
	if (Empreinte::modele.empty())
	{
		string line;
		ifstream is(FICHIER_METADONNEES);
		while (getline(is, line))
		{
			int pos = line.find(';');
			string type = line.substr(pos + 1);
			string nomAtt = line.substr(0, pos);
			if (type == "string")
			{
				Empreinte::modele.push_back(0);
				Empreinte::nomAttribut.push_back(nomAtt);
			}
			else if (type == "double")
			{
				Empreinte::modele.push_back(1);
				Empreinte::nomAttribut.push_back(nomAtt);
			}
		}
		is.close();
	}
}

Empreinte::~Empreinte()
{
	cout << "Destruction de  l'empreinte" << endl;
}

double Empreinte::distance(Empreinte empreinte)
{
	cout << "Calcule de la distance de  l'empreinte : " << empreinte->NoID << endl;
	double distanceEmpreinte = 0;
	vector<Attribut *> vecteurAttributs = empreinte.listeAttributs;
	for (unsigned int i = 0; i < modele.size(); i++)
	{
		if (modele[i] == 0)
		{
			distanceEmpreinte = distanceEmpreinte + listeAttributs[i]->distance(vecteurAttributs[i]);
		}
		else
		{
			distanceEmpreinte = distanceEmpreinte + listeAttributs[i]->distance(vecteurAttributs[i]);
		}
	}
	distanceEmpreinte = distanceEmpreinte / modele.size();
	return distanceEmpreinte;
}

void Empreinte::sauvegarderEmpreinte()
{
	cout << "Sauvegarder l'empreinte" << endl;
	ofstream os;
	os.open(FICHIER_EMPREINTES, std::ofstream::out | std::ofstream::app);
	os << NoID;
	for (int i = 0; i < listeAttributs.size(); i++)
	{
		if (modele[i] == 0)
		{
			AttributString *attributString = dynamic_cast<AttributString *>(listeAttributs[i]);
			os << ";" << attributString->getData();
		}
		else
		{
			AttributDouble *attributDouble = dynamic_cast<AttributDouble *>(listeAttributs[i]);
			os << ";" << attributDouble->getData();
		}
	}
	os << endl;
	os.close();
}

int Empreinte::getID()
{
	return NoID;
}

vector<Attribut *> Empreinte::getListeAttributs()
{
	return listeAttributs;
}