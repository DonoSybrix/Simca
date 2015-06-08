/*
 * networkEngine.cpp
 *
 *  Created on: 13 avr. 2011
 *      Author: Axel GUILMIN
 *
 *  Le moteur réseau est pensé pour ne pas creer deux fois en mémoire les memes enregistrement
 *  c-a-d, si on demande les données d'un enregistrement déja chargé en mémoire,
 *  c'est un pointeur vers l'objet déja chargé qui est retourné.
 *
 *
 *	TODO: Fuite memoire dans Test a supprimer ?
 *
 *	TODO: ->SetNom() verifier les données
 *
 */

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "NetworkEngine.hpp"


////////////////////////////////////////////////////////////
// Test the class
////////////////////////////////////////////////////////////
void NetworkEngine::Demo()
{
	// --- INSERT --- //

	// Remplissage d'une base vide avec des données de test
	// un SetXxx() retourne toujours l'id de l'enregistrement ou leve une erreur si une contrainte de la BDD n'est pas respecté (nom unique, clé etrangere, etc)

	try
	{
		Crossroad* cr = NewCrossroad("test1") ;
		cr->SetHeight(50) ;
		cr->SetWidth(50) ;
		SaveCrossroad(cr);

		Road* road = NewRoad("Angers", cr);
		SaveRoad(road) ;
		Road* road2 = NewRoad("Paris", cr);
		SaveRoad(road2) ;
		Road* road3 = NewRoad("Nantes", cr);
		SaveRoad(road3) ;

		Simulation* simu1 = NewSimulation("simu1", cr);
		SaveSimulation(simu1);
		Simulation* simu2 = NewSimulation("simu2", cr);
		SaveSimulation(simu2);

		Result* res1 = NewResult(road, simu1) ;
		res1->SetTempsCumul(923456);
		res1->SetTempsEcartType(2);
		res1->SetTempsMax(50);
		res1->SetTempsMoyen(20);
		res1->SetDeuxFeux(25.4);
		SaveResult(res1);
		Result* res2 = NewResult(road2, simu1) ;
		SaveResult(res2);
		Result* res3 = NewResult(road3, simu1) ;
		SaveResult(res3);
	}
	catch(const std::exception& e)
	{
	   std::cout<<e.what()<<std::endl;
	}

	try
	{
		Crossroad* cr2 = NewCrossroad("test2");
		cr2->SetHeight(80);
		cr2->SetWidth(80);
		SaveCrossroad(cr2);
	}
	catch(const std::exception& e)
	{
	   std::cout<<e.what()<<std::endl;
	}

	// --- SELECT --- //
	// Recuperer des donées a partir de la BDD

	Crossroad * test;
	std::vector<Road*> routesDeTest;
	std::vector<Simulation*> simulationsDeTest;
	std::vector<Result*> resultatsDeTestSimulation1;
	try
	{
		// Le carrefour id 1 s'apelle test1 la premiere fois
		test = GetCrossroad(1);
	}
	catch(const std::exception& e)
	{
	   std::cout<<e.what()<<std::endl;
	}

	try
	{
		// Redemander le chargement du meme rond-point -> meme pointeur
		test = GetCrossroad("test1");

		// Charger les routes associées au rond-point
		std::set<int>::const_iterator it1 (test->roads.begin()), end1(test->roads.end());
		for(;it1!=end1;++it1)
			routesDeTest.push_back(GetRoad(*it1));

		// Charger les Simulation associées au rond-point
		std::set<int>::const_iterator it2 (test->simulations.begin()), end2(test->simulations.end());
		for(;it2!=end2;++it2)
			simulationsDeTest.push_back(GetSimulation(*it2));

		// Charger les resultats de la premiere simulation sur ce Rond-point
		std::vector<Road*>::const_iterator it6 (routesDeTest.begin()), end6(routesDeTest.end());
		for(;it6!=end6;++it6)
		resultatsDeTestSimulation1.push_back(GetResult(*it6, *simulationsDeTest.begin()));
	}
	catch(const std::exception& e)
	{
	   std::cout<<e.what()<<std::endl;
	}

	// Pour avoir tout les carrefour dans un std::vector<Crossroad*>
	GetAllCrossroad();


	// --- UPDATE --- //
	// On considere que des modifs on été apportés sur les objets
	try
	{
		// int idCr = SaveCrossroad(test) ;

		std::vector<Road*>::const_iterator it3(routesDeTest.begin()), end3(routesDeTest.end());
		for(;it3!=end3;++it3)
			SaveRoad(*it3);        void SetAngle(float angle);

		std::vector<Simulation*>::const_iterator it4(simulationsDeTest.begin()), end4(simulationsDeTest.end());
		for(;it4!=end4;++it4)
			SaveSimulation(*it4);

		std::vector<Result*>::const_iterator it5(resultatsDeTestSimulation1.begin()), end5(resultatsDeTestSimulation1.end());
		for(;it5!=end5;++it5)
			SaveResult(*it5);
	}
	catch(const std::exception& e)
	{
	   std::cout<<e.what()<<std::endl;
	}

	// --- DELETE --- //
	// Penser a mettre a jour les vecteur sur pointeurs car la suppression se fait en cascade

	//DelCrossroad(test) ;
}

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
NetworkEngine::NetworkEngine()
{

}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
NetworkEngine::~NetworkEngine()
{

}

////////////////////////////////////////////////////////////
/// Fonctions générales
////////////////////////////////////////////////////////////
void NetworkEngine::Frame()
{
	// Do nothing
}


void NetworkEngine::Connect() throw(std::runtime_error)
{
	std::cout<<this->requete<<std::endl;
	std::cout.flush();
	connexion = sqlite3_open("../data/db/sqlite.db", &dataBase);
	if( connexion )
	{
		throw std::runtime_error("Can't open database: " + toString(sqlite3_errmsg(dataBase)));
		sqlite3_close(dataBase);
	}
}

void NetworkEngine::Query(sqlite3_callback callback,void *param) throw(std::logic_error,std::runtime_error)
{
	try
	{
		this->Connect() ;
		// c_str() converti une string en char*
		this->connexion = sqlite3_exec(this->dataBase, this->requete.c_str(), callback, param, &errorMsg);
		this->Disconnect() ;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

int NetworkEngine::QueryCount() throw(std::logic_error,std::runtime_error)
{ // Methode a n'apeller que pour count(*), retourne la valeur (int) de la premiere ligne, premiere colone
	char** table;
	int* nbRow = 0;
	int* nbColumn = 0;

	try
	{
		this->Connect() ;
		// c_str() converti une string en char*
		this->connexion = sqlite3_get_table(this->dataBase, this->requete.c_str(), &table, nbRow, nbColumn, &errorMsg);
		this->Disconnect() ;

		return toInt(table[1]);
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

void NetworkEngine::Disconnect() throw(std::logic_error)
{
	if( connexion!=SQLITE_OK )
	{
		throw std::logic_error("SQLite: " + toString(sqlite3_errmsg(dataBase)));
		sqlite3_free(errorMsg);
	}
	sqlite3_close(dataBase);
}

////////////////////////////////////////////////////////////
/// Recuperer tous les carrefours
////////////////////////////////////////////////////////////
std::vector<Crossroad*> NetworkEngine::GetAllCrossroad()
{
	std::vector<Crossroad*> retour ;

	char** ids;
	int nbRow = 0;
	int nbColumn = 0;

	this->requete = "SELECT idCarrefour FROM Carrefour;";

	this->Connect() ;
	// c_str() converti une string en char*
	this->connexion = sqlite3_get_table(this->dataBase, this->requete.c_str(), &ids, &nbRow, &nbColumn, &errorMsg);
	this->Disconnect() ;

	for(int i=0; i<nbRow; i++)
		retour.push_back(GetCrossroad(toInt(ids[i+1])));

	return retour ;
}

////////////////////////////////////////////////////////////
/// Carrefour
////////////////////////////////////////////////////////////

Crossroad* NetworkEngine::NewCrossroad(std::string nom) throw(std::logic_error)
{
	// Tester si enregistrement BDD sera possible
	this->requete = "SELECT count(idCarrefour) FROM Carrefour WHERE nom = \"" + nom + "\";";
	int a = this->QueryCount();

	if(a > 0)
		throw std::logic_error("Il existe deja un carrefour avec le nom \"" + nom + "\".") ;

	std::set<Crossroad*>::const_iterator it(this->crossroads.begin()), end(this->crossroads.end());
	for(;it!=end;++it)
		if((*it)->GetNom().compare(nom) == 0)
			throw std::logic_error("Il existe deja un carrefour avec le nom \"" + nom + "\".") ;

	// Creer une nouvelle instance
	Crossroad* returnedCrossroad = new Crossroad(nom);

	// Id à 0 signifie que l'enregistrement en BDD n'est pas fait
	returnedCrossroad->SetIdCarrefour(0);

	// Memoriser instance
	this->crossroads.insert(returnedCrossroad);

	return returnedCrossroad ;
}

Crossroad* NetworkEngine::GetCrossroad(std::string nom) throw(std::logic_error)
{
	// Si déja instancié, on retourne le pointeur vers l'instance
	std::set<Crossroad*>::const_iterator it(this->crossroads.begin()), end(this->crossroads.end());
	for(;it!=end;++it)
		if((*it)->GetNom().compare(nom) == 0)
			return *it;

    // Creer instance, id = 0 par défaut
	Crossroad* returnedCrossroad = new Crossroad(nom);
	returnedCrossroad->SetIdCarrefour(0);

	// Construction de la requete
	this->requete = "SELECT Carrefour.idCarrefour, Carrefour.nom, rayon, idArtere, idSimulation	FROM Carrefour LEFT JOIN Artere ON Carrefour.idCarrefour = Artere.idCarrefour LEFT JOIN Simulation ON Carrefour.idCarrefour = Simulation.idCarrefour WHERE Carrefour.nom =\"" + nom  + "\";" ;

	// Infos renseigné dans le callback
	this->Query(GetCrossroadCallback,&returnedCrossroad) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedCrossroad->GetIdCarrefour() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->crossroads.insert(returnedCrossroad);

	return returnedCrossroad;
}

Crossroad* NetworkEngine::GetCrossroad(unsigned int id) throw(std::logic_error)
{
	// Si déja instancié, on retourne le pointeur vers l'instance
	std::set<Crossroad*>::iterator it ;
	for(it=this->crossroads.begin();it!=this->crossroads.end();++it)
		if((*it)->GetIdCarrefour() == id)
			return *it;

    // Creer instance
	Crossroad* returnedCrossroad = new Crossroad();
	returnedCrossroad->SetIdCarrefour(0);

	// Construction de la requete
	this->requete = "SELECT Carrefour.idCarrefour, Carrefour.nom, rayon, idArtere, idSimulation \
			FROM Carrefour \
			LEFT JOIN Artere ON Carrefour.idCarrefour = Artere.idCarrefour \
			LEFT JOIN Simulation ON Carrefour.idCarrefour = Simulation.idCarrefour \
			WHERE Carrefour.idCarrefour =" + toString(id)  + ";" ;

	// Infos renseigné dans le callback
	this->Query(GetCrossroadCallback,&returnedCrossroad) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedCrossroad->GetIdCarrefour() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->crossroads.insert(returnedCrossroad);

	return returnedCrossroad;
}

int NetworkEngine::GetCrossroadCallback(void* pReturnedCrossroad, int nbLigne, char **values, char **colNames)
{
	// Recuperer le pointeur sur l'instance de Crossroad a modifier
	Crossroad* carrefour = *(Crossroad**)pReturnedCrossroad ;

	carrefour->SetIdCarrefour(toInt(values[0])) ;
	carrefour->SetNom(values[1]) ;
	carrefour->SetHeight(toInt(values[2])*2) ;
	carrefour->SetWidth(toInt(values[2])*2) ;

	// Enregistrement des idArtere et simulation correspondant
	if(values[3]!=NULL)
	carrefour->roads.insert(toInt(values[3]));
	if(values[4]!=NULL)
	carrefour->simulations.insert(toInt(values[4]));

	return 0;
}

int NetworkEngine::SaveCrossroad(Crossroad* crossroad)
{
	// Si l'id est null, creer un nouvel enregistrement
	if( crossroad->GetIdCarrefour() == 0 )
	{
		this->requete = "INSERT INTO Carrefour VALUES(NULL,\"" + crossroad->GetNom() + "\"," + toString(crossroad->GetWidth()/2) + ");" ;
		this->Query() ;
		// Memoriser l'id généré
		crossroad->SetIdCarrefour(sqlite3_last_insert_rowid(dataBase)) ;
		std::cout<<"last_insert_rowid : "<<sqlite3_last_insert_rowid(dataBase)<<std::endl;
	}
	// Sinon c'est une mise a jour
	else
	{
		this->requete = "UPDATE Carrefour SET nom=\"" + crossroad->GetNom() + "\", rayon=" + toString(crossroad->GetWidth()/2) + " WHERE idCarrefour =" + toString(crossroad->GetIdCarrefour()) + ";" ;
		this->Query() ;
	}
	return crossroad->GetIdCarrefour();
}

void NetworkEngine::DelCrossroad(Crossroad* crossroad)
{
	// -----
	// Parceque la suppression en cascade ne veut pas marcher dans SQlite !
	// TODO : Supprimer les artere liés
    // -----

	// Supprimer le pointeur du vecteur
	this->crossroads.erase(crossroad);

	// Supprimer de la base de données
	if(crossroad->GetIdCarrefour()!=0)
	{
		this->requete = "DELETE FROM Carrefour WHERE idCarrefour =" + toString(crossroad->GetIdCarrefour())  + ";" ;
		this->Query() ;
	}
}


////////////////////////////////////////////////////////////
/// Artere
////////////////////////////////////////////////////////////

Road* NetworkEngine::NewRoad(std::string nom, Crossroad* crossroad) throw(std::logic_error)
{
	// Tester si enregistrement BDD sera possible
	this->requete = "SELECT count(idArtere) FROM Artere WHERE nom = \"" + nom + "\" AND idCarrefour =" + toString(crossroad->GetIdCarrefour()) + ";";
	int a = this->QueryCount();

	if(a > 0)
		throw std::logic_error("Il existe deja une Artere avec le nom \"" + nom + "\" pour ce rond-point.") ;

	std::set<Road*>::const_iterator it(this->roads.begin()), end(this->roads.end());
	for(;it!=end;++it)
		if((*it)->GetNom().compare(nom) == 0 && (*it)->GetCrossroad()->GetIdCarrefour() == crossroad->GetIdCarrefour())
			throw std::logic_error("Il existe deja une Artere avec le nom \"" + nom + "\" pour ce rond-point.") ;

	// Creer une nouvelle instance
	Road* returnedRoad = new Road(nom, crossroad);

	// Id à 0 signifie que l'enregistrement en BDD n'est pas fait
	returnedRoad->SetIdArtere(0);

	// Memoriser instance
	this->roads.insert(returnedRoad);

	return returnedRoad ;
}

Road* NetworkEngine::GetRoad(Crossroad* crossroad, std::string nom) throw(std::logic_error)
{
	// Si déja instanciee, on retourne le pointeur vers l'instance
	std::set<Road*>::const_iterator it(this->roads.begin()), end(this->roads.end());
	for(;it!=end;++it)
		if((*it)->GetNom().compare(nom) == 0 && (*it)->GetCrossroad()->GetIdCarrefour() == crossroad->GetIdCarrefour())
			return *it;

	// Creer instance, id = 0 par défaut
	Road* returnedRoad = new Road() ;
	returnedRoad->SetIdArtere(0) ;

	// Construction de la requete
	this->requete = "SELECT * FROM Artere WHERE nom =\"" + nom  + "\" AND idCarrefour =" + toString(crossroad->GetIdCarrefour()) + ";" ;

	this->Query(GetRoadCallback,&returnedRoad) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedRoad->GetIdArtere() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->roads.insert(returnedRoad);

	return returnedRoad;
}

Road* NetworkEngine::GetRoad(unsigned int id) throw(std::logic_error)
{
	// Si déja instanciee, on retourne le pointeur vers l'instance
	std::set<Road*>::const_iterator it(this->roads.begin()), end(this->roads.end());
	for(;it!=end;++it)
		if((*it)->GetIdArtere() == id)
			return *it;

	// Creer instance, id = 0 par défaut
	Road* returnedRoad = new Road() ;
	returnedRoad->SetIdArtere(0) ;

	// Construction de la requete
	this->requete = "SELECT * FROM Artere WHERE idArtere =" + toString(id)  + ";" ;
	this->Query(GetRoadCallback,&returnedRoad) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedRoad->GetIdArtere() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->roads.insert(returnedRoad);

	return returnedRoad;
}

int NetworkEngine::GetRoadCallback(void* pReturnedRoad, int nbLigne, char **values, char **colNames)
{
	// Recuperer le pointeur sur l'instance de Road a modifier
	Road* artere = *(Road**)pReturnedRoad ;

	// Charger en memoire les données
	artere->SetIdArtere(toInt(values[0]));
	artere->SetNom(values[1]);
	artere->SetDebit(toInt(values[2]));
	artere->SetRadius(toFloat(values[3]));
	artere->SetDureeFeuVert(toInt(values[4]));
	artere->SetPositionFeu(toInt(values[5]));
	artere->SetDelaiAvantSuivant(toInt(values[6]));
	// Get carrefour retourne le pointeur vers l'instance si elle est déja crée
	int idCarrefour = toInt(values[7]) ;
	Crossroad* pCarrefour = NetworkEngine::getInstance()->GetCrossroad(idCarrefour) ;
	artere->SetCrossroad(pCarrefour);
	return 0;
}

// Pour enregistrer une Artere en BDD, le carrefour correspondant doit déja avoir été enregistré
int NetworkEngine::SaveRoad(Road* road)
{
	// Si l'id est null, creer un nouvel enregistrement
	if( road->GetIdArtere() == 0 )
	{
		this->requete = "INSERT INTO Artere VALUES(NULL,\"" +
				road->GetNom() + "\"," +
				toString(road->GetDebit()) + "," +
				toString(road->GetRadius()) + "," +
				toString(road->GetDureeFeuVert()) + "," +
				toString(road->GetPositionFeu()) + "," +
				toString(road->GetDelaiAvantSuivant()) + "," +
				toString(road->GetCrossroad()->GetIdCarrefour()) + ");" ;

		this->Query() ;
		//On retourne l'id de l'enregistrement ajouté
		road->SetIdArtere(sqlite3_last_insert_rowid(dataBase)) ;
	    road->GetCrossroad()->roads.insert(sqlite3_last_insert_rowid(dataBase));
	    std::cout<<"last_insert_rowid : "<<sqlite3_last_insert_rowid(dataBase)<<std::endl;
	}
	// maj BDD
	else
	{
		this->requete = "UPDATE Artere SET "
				"nom=\"" + road->GetNom() + "\"," +
				"debit=" + toString(road->GetDebit()) + "," +
				"angle=" + toString(road->GetRadius()) + "," +
				"dureeFeuVert=" + toString(road->GetDureeFeuVert()) + "," +
				"positionFeu=" + toString(road->GetPositionFeu()) + "," +
				"delaiAvantSuivant=" + toString(road->GetDelaiAvantSuivant()) + "," +
				"idCarrefour=" + toString(road->GetCrossroad()->GetIdCarrefour()) +
				" WHERE idArtere =" + toString(road->GetIdArtere()) + ";" ;
		this->Query() ;
	}
	return road->GetIdArtere() ;
}

void NetworkEngine::DelRoad(Road* road)
{
	// Supprimer le pointeur du vecteur
	this->roads.erase(road);

	if(road->GetIdArtere()!=0)
	{
		// Annoncer au crossroad la suppression
		road->GetCrossroad()->roads.erase(road->GetIdArtere());
		// Supprimer de la base de données
		this->requete = "DELETE FROM Artere WHERE idArtere =" + toString(road->GetIdArtere())  + ";" ;
		this->Query() ;
	}
}

////////////////////////////////////////////////////////////
/// Simulation
////////////////////////////////////////////////////////////

Simulation* NetworkEngine::NewSimulation(std::string nom, Crossroad* crossroad) throw(std::logic_error)
{
	// Tester si enregistrement BDD sera possible
	this->requete = "SELECT count(idSimulation) FROM Simulation WHERE nom = \"" + nom + "\" AND idCarrefour =" + toString(crossroad->GetIdCarrefour()) + ";";
	int a = this->QueryCount();

	if(a > 0)
		throw std::logic_error("Il existe deja une Simulation avec le nom \"" + nom + "\" pour ce rond-point.") ;

	std::set<Simulation*>::const_iterator it(this->simulations.begin()), end(this->simulations.end());
	for(;it!=end;++it)
		if((*it)->GetNom().compare(nom) == 0 && (*it)->GetCrossroad()->GetIdCarrefour() == crossroad->GetIdCarrefour())
			throw std::logic_error("Il existe deja une Simulation avec le nom \"" + nom + "\" pour ce rond-point.") ;

	// Creer une nouvelle instance
	Simulation* returnedSimulation = new Simulation(nom, crossroad);

	// Id à 0 signifie que l'enregistrement en BDD n'est pas fait
	returnedSimulation->SetIdSimulation(0);

	// Memoriser instance
	this->simulations.insert(returnedSimulation);

	return returnedSimulation ;
}

Simulation* NetworkEngine::GetSimulation(Crossroad* crossroad, std::string nom) throw(std::logic_error)
{
	// Si déja instanciee, on retourne le pointeur vers l'instance
	std::set<Simulation*>::const_iterator it(this->simulations.begin()), end(this->simulations.end());
	for(;it!=end;++it)
		if((*it)->GetNom().compare(nom) == 0 && (*it)->GetCrossroad()->GetIdCarrefour() == crossroad->GetIdCarrefour())
			return *it;

	// Creer instance, id = 0 par défaut
	Simulation* returnedSimulation = new Simulation() ;
	returnedSimulation->SetIdSimulation(0) ;

	// Construction de la requete
	this->requete = "SELECT * FROM Simulation WHERE nom =\"" + nom  + "\" AND idCarrefour =" + toString(crossroad->GetIdCarrefour()) + ";" ;
	this->Query(GetSimulationCallback,&returnedSimulation) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedSimulation->GetIdSimulation() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->simulations.insert(returnedSimulation);

	return returnedSimulation;
}

Simulation* NetworkEngine::GetSimulation(unsigned int id) throw(std::logic_error)
{
	// Si déja instanciee, on retourne le pointeur vers l'instance
	std::set<Simulation*>::const_iterator it(this->simulations.begin()), end(this->simulations.end());
	for(;it!=end;++it)
		if((*it)->GetIdSimulation() == id)
			return *it;

	// Creer instance, id = 0 par défaut
    Simulation* returnedSimulation = new Simulation();
    returnedSimulation->SetIdSimulation(0);

	// Construction de la requete
    this->requete = "SELECT * FROM Simulation WHERE idSimulation =" + toString(id)  + ";" ;
	this->Query(GetSimulationCallback,&returnedSimulation) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedSimulation->GetIdSimulation() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->simulations.insert(returnedSimulation);

	return returnedSimulation;
}

int NetworkEngine::GetSimulationCallback(void* pReturnedSimulation, int nbLigne, char **values, char **colNames)
{
	// Recuperer le pointeur sur l'instance de Simulation a modifier
	Simulation* simulation = *(Simulation**)pReturnedSimulation ;

	// Charger en memoire les données
	simulation->SetIdSimulation(toInt(values[0]));
	simulation->SetNom(values[1]);
	simulation->SetDateHeureDeb(toInt(values[2]));
	simulation->SetDateHeureFin(toInt(values[3]));
	// Get simulation retourne le pointeur vers l'instance si elle est déja crée
	int idCarrefour = toInt(values[4]) ;
	Crossroad* pCarrefour = NetworkEngine::getInstance()->GetCrossroad(idCarrefour) ;
	simulation->SetCrossroad(pCarrefour);
	return 0;
}

// Pour enregistrer une Artere en BDD, le carrefour correspondant doit déja avoir été enregistré
int NetworkEngine::SaveSimulation(Simulation* simulation)
{
	// Si l'id est null, creer un nouvel enregistrement
	if( simulation->GetIdSimulation() == 0 )
	{
		this->requete = "INSERT INTO Simulation VALUES(NULL,\"" +
				simulation->GetNom() + "\"," +
				toString(simulation->GetDateHeureDeb()) + "," +
				toString(simulation->GetDateHeureFin()) + "," +
				toString(simulation->GetCrossroad()->GetIdCarrefour()) + ");" ;
		this->Query() ;
		simulation->SetIdSimulation(sqlite3_last_insert_rowid(dataBase));
		simulation->GetCrossroad()->simulations.insert(sqlite3_last_insert_rowid(dataBase));
		std::cout<<"last_insert_rowid : "<<sqlite3_last_insert_rowid(dataBase)<<std::endl;
	}
	// maj BDD
	else
	{
		this->requete = "UPDATE Simulation SET "
				"nom=\"" + simulation->GetNom() + "\"," +
				"dateHeureDeb=" + toString(simulation->GetDateHeureDeb()) + "," +
				"dateHeureFin=" + toString(simulation->GetDateHeureFin()) + "," +
				"idCarrefour=" + toString(simulation->GetCrossroad()->GetIdCarrefour()) +
				" WHERE idSimulation =" + toString(simulation->GetIdSimulation()) + ";" ;
		this->Query() ;
	}
	// On retourne l'id de l'enregistrement
	return simulation->GetIdSimulation() ;
}

void NetworkEngine::DelSimulation(Simulation* simulation)
{
	// Supprimer le pointeur du vecteur
	this->simulations.erase(simulation);

	if(simulation->GetIdSimulation()!=0)
	{
		// Annoncer au crossroad la suppression
		simulation->GetCrossroad()->simulations.erase(simulation->GetIdSimulation());
		// Supprimer de la base de données
		this->requete = "DELETE FROM Simulation WHERE idSimulation =" + toString(simulation->GetIdSimulation())  + ";" ;
		this->Query() ;
	}
}

////////////////////////////////////////////////////////////
/// ResultArtere
////////////////////////////////////////////////////////////

Result* NetworkEngine::NewResult(Road* road, Simulation* simulation) throw(std::logic_error)
{
	// Tester si enregistrement BDD sera possible
	this->requete = "SELECT count(idResultatArtere) FROM ResultatArtere WHERE idArtere = " + toString(road->GetIdArtere()) + " AND idSimulation =" + toString(simulation->GetIdSimulation()) + ";";
	int a = this->QueryCount();

	if(a > 0)
		throw std::logic_error("Il existe deja des resultats pour cette artere dans cette simulation.") ;

	std::set<Result*>::const_iterator it(this->results.begin()), end(this->results.end());
	for(;it!=end;++it)
		if( (*it)->GetRoad()->GetIdArtere() == road->GetIdArtere() && (*it)->GetSimulation()->GetIdSimulation() == simulation->GetIdSimulation())
			throw std::logic_error("Il existe deja des resultats pour cette artere dans cette simulation.") ;

	// Creer une nouvelle instance
	Result* returnedResult = new Result(road, simulation);

	// Id à 0 signifie que l'enregistrement en BDD n'est pas fait
	returnedResult->SetIdResultatArtere(0);

	// Memoriser instance
	this->results.insert(returnedResult);

	return returnedResult ;
}

Result* NetworkEngine::GetResult(Road* road, Simulation* simulation) throw(std::logic_error)
{
	// Si déja instanciee, on retourne le pointeur vers l'instance
	std::set<Result*>::const_iterator it(this->results.begin()), end(this->results.end());
	for(;it!=end;++it)
		if((*it)->GetRoad() == road && (*it)->GetSimulation() == simulation)
			return *it;


	// Creer instance, id = 0 par défaut
	Result* returnedResult = new Result() ;
	returnedResult->SetIdResultatArtere(0) ;

	// Construction de la requete
    this->requete = "SELECT * FROM ResultatArtere WHERE idArtere =" + toString(road->GetIdArtere())  + " AND idSimulation=" + toString(simulation->GetIdSimulation()) + ";" ;
	this->Query(GetResultCallback,&returnedResult) ;

	// Si l'enregistrement n'existe pas en BDD, on remonte une execption
	if( returnedResult->GetIdResultatArtere() == 0 )
		throw std::logic_error("Aucun enregistrement correspondant en BDD");

	// Memoriser l'instance
	this->results.insert(returnedResult);

	return returnedResult;
}

int NetworkEngine::GetResultCallback(void* pReturnedResult, int nbLigne, char **values, char **colNames)
{
	// Recuperer le pointeur sur l'instance de Simulation a modifier
	Result* result = *(Result**)pReturnedResult ;

	// Charger en memoire les données
	result->SetIdResultatArtere(toInt(values[0]));
	result->SetTempsMoyen(toInt(values[1]));
	result->SetTempsCumul(toInt(values[2]));
	result->SetTempsMax(toInt(values[3]));
	result->SetTempsEcartType(toInt(values[4]));
	result->SetDeuxFeux(toFloat(values[5]));
	// Get road retourne le pointeur vers l'instance si elle est déja crée
	int idArtere = toInt(values[6]) ;
	Road* pArtere = NetworkEngine::getInstance()->GetRoad(idArtere) ;
	result->SetRoad(pArtere);
	// Get simulation retourne le pointeur vers l'instance si elle est déja crée
	int idSimulation = toInt(values[7]) ;
	Simulation* pSimulation = NetworkEngine::getInstance()->GetSimulation(idSimulation) ;
	result->SetSimulation(pSimulation);

	return 0;
}

// Pour enregistrer une Artere en BDD, le carrefour correspondant doit déja avoir été enregistré
int NetworkEngine::SaveResult(Result* result)
{

	// Si l'id est null, creer un nouvel enregistrement
	if( result->GetIdResultatArtere() == 0 )
	{
		this->requete = "INSERT INTO ResultatArtere VALUES(NULL," +
				toString(result->GetTempsMoyen()) + "," +
				toString(result->GetTempsCumul()) + "," +
				toString(result->GetTempsMax()) + "," +
				toString(result->GetTempsEcartType()) + "," +
				toString(result->GetDeuxFeux()) + "," +
				toString(result->GetRoad()->GetIdArtere()) + "," +
				toString(result->GetSimulation()->GetIdSimulation()) + ");" ;
		this->Query();
		result->SetIdResultatArtere(sqlite3_last_insert_rowid(dataBase)) ;
		std::cout<<"last_insert_rowid : "<<sqlite3_last_insert_rowid(dataBase)<<std::endl;
	}
	// maj BDD
	else
	{
		this->requete = "UPDATE ResultatArtere SET "
				"tempsMoyen=" + toString(result->GetTempsMoyen()) + "," +
				"tempsCumul=" + toString(result->GetTempsCumul()) + "," +
				"tempsMax=" + toString(result->GetTempsMax()) + "," +
				"tempsEcartType=" + toString(result->GetTempsEcartType()) + "," +
				"deuxFeux=" + toString(result->GetDeuxFeux()) + "," +
				"idArtere=" + toString(result->GetRoad()->GetIdArtere()) + "," +
				"idSimulation=" + toString(result->GetSimulation()->GetIdSimulation()) +
				" WHERE idResultatArtere =" + toString(result->GetIdResultatArtere()) + ";" ;
		this->Query();
	}

	// On retourne l'id de l'enregistrement
	return result->GetIdResultatArtere() ;
}

void NetworkEngine::DelResult(Result* result)
{
	// Supprimer le pointeur du vecteur
	this->results.erase(result);

	// Supprimer de la base de données
	if(result->GetIdResultatArtere()!=0)
	{
		this->requete = "DELETE FROM ResultatArtere WHERE idResultatArtere =" + toString(result->GetIdResultatArtere())  + ";" ;
		this->Query();
	}
}
