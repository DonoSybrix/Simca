/*
 * Pdf.cpp
 *
 *  Created on: 26 avr. 2011
 *      Author: Axel GUILMIN
 */

#include "Pdf.hpp"

Pdf::Pdf(Simulation* simulation)
{
	this->simulation = simulation;

	std::string nom = "Rapport de " + this->simulation->GetNom() ;

	// Les nom des fichiers, entourée de " au cas ou il contienent des es
	this->fileTex = "../data/tex/" + nom + ".tex";
	this->fileAux = "../data/pdf/" + nom + ".aux";
	this->fileLog = "../data/pdf/" + nom + ".log";
	this->filePdf = "../data/pdf/" + nom + ".pdf";
}

Pdf::~Pdf()
{

}

// Genere le pdf en appelant pdflatex, supprimes les fichiers temporaire crées
void Pdf::TexToPdf()
{
	// commande "pdflatex -output-directory ../data/pdf/ ../data/tex/rapport.tex
	std::string cmd = "pdflatex -interaction nonstopmode -output-directory ../data/pdf/ \"" + this->fileTex + "\"";
	std::system(cmd.c_str());

	#if ! defined (OS_WIN) // Linux
		// commande "rm ../data/pdf/rapport.aux"
		cmd = "rm \"" + this->fileAux + "\"";
		std::system(cmd.c_str());
		// commande "rm ../data/pdf/rapport.log"
		cmd = "rm \"" + this->fileLog + "\"";
		std::system(cmd.c_str());
	#endif
	#if defined (OS_WIN) // Windows
		// commande "del ../data/pdf/rapport.aux"
		cmd = "del \"" + this->fileAux + "\"";
		std::system(cmd.c_str());
		// commande "del ../data/pdf/rapport.log"
		cmd = "del \"" + this->fileLog + "\"";
		std::system(cmd.c_str());
	#endif
}

// Creer le fichier tex a partir des donnees
void Pdf::DataTotex()
{
	// Ouverture du fichier en ecriture, ecrase s'il existe deja
	std::ofstream fichier(this->fileTex.c_str(),std::ios::out);

	// Tester l'ouverture
	if(! fichier)
		throw std::runtime_error("Erreur lors de la creation du fichier tex");

	// Calcul de la duree de la simulation
	unsigned int duree = this->simulation->GetDateHeureFin() - this->simulation->GetDateHeureDeb() ;

	// Generation ou recuperation du screenshot TODO

	//id des arteres concernées
	std::set<int>::const_iterator itRoads(this->simulation->GetCrossroad()->roads.begin()), endRoads(this->simulation->GetCrossroad()->roads.end());

	// Ecriture dans le fichier
	// --- Entete ---
	fichier
		<< "\\documentclass[a4paper,12pt]{article}" 		<< std::endl
															<< std::endl
		<< "\\usepackage{graphicx}" 						<< std::endl
		<< "\\usepackage[utf8]{inputenc}" 					<< std::endl
		<< "\\usepackage[francais]{babel}" 					<< std::endl
		<< "\\usepackage[table]{xcolor}" 					<< std::endl
															<< std::endl
		<< "\\selectlanguage{francais}" 					<< std::endl
		<< "\\title{Compte-rendu de la simulation ``" << this->simulation->GetNom() << "''}" 		<< std::endl
		<< "\\author{SIMCA}" 								<< std::endl
															<< std::endl
	// --- Page 1 : Infos sur la simulation --- //
		<< "\\begin{document}" 								<< std::endl
															<< std::endl
		<< "{\\bfseries\\maketitle}" 						<< std::endl
															<< std::endl
		<< "\\begin{tabular}{r|l}" 							<< std::endl
		<< "Carrefour 								& "  << this->simulation->GetCrossroad()->GetNom() 	<< "\\\\" << std::endl
		<< "Nom de la simulation					& "  << this->simulation->GetNom() 					<< "\\\\" << std::endl
		<< "Heure de début dans le simulation 		& $"  << secondsToTime(this->simulation->GetDateHeureDeb())			<< "$ \\\\" << std::endl
		<< "Heure de fin dans le simulation 		& $"  << secondsToTime(this->simulation->GetDateHeureFin())			<< "$ \\\\" << std::endl
		<< "Durée									& $"  << secondsToTime(duree) 										<< "$"	   << std::endl
		<< "\\end{tabular}" 								<< std::endl
															<< std::endl
		<< "\\vspace{0.5cm}" 								<< std::endl
															<< std::endl
		<< "\\begin{flushleft}" 							<< std::endl
		<< "\\includegraphics[width=13.5cm]{../data/screenshots/example}" << std::endl
		<< "\\end{flushleft}" 								<< std::endl
															<< std::endl
		<< "\\newpage		" 								<< std::endl
															<< std::endl
	// --- Page 2 : Configuration --- ///
		<< "\\part*{Configuration des feux}" 				<< std::endl
															<< std::endl
		<< "Configuration des feux dans l'ordre de leur passage au vert : Direction de provenance, nombre de véhicules par heure, durée du feux vert et le délai avant que le prochain feux vert ne s'allume." << std::endl
		<< "\\vspace{0.5cm}" 								<< std::endl
															<< std::endl
		<< "\\hrulefill " 									<< std::endl
															<< std::endl
	;
	// Pour chaque artere du rond-point
	for(;itRoads!=endRoads;++itRoads)
	{
		Road* artere = NetworkEngine::getInstance()->GetRoad(*itRoads);
		fichier
			<< "\\renewcommand\\arraystretch{1.2}" 																		<< std::endl
			<< "\\begin{tabular}{r|l}" 																					<< std::endl
			<< "Artere & {\\bfseries " 	<< artere->GetNom() 								<< "} \\\\" 				<< std::endl
			<< "Trafic & " 				<< artere->GetDebit() 								<< " véhicule/heure \\\\" 	<< std::endl
			<< "Durrée & $" 			<< secondsToTime(artere->GetDureeFeuVert())			<< "$ \\\\" 				<< std::endl
			<< "Délai & $" 				<< secondsToTime(artere->GetDelaiAvantSuivant()) 	<< "$ \\\\" 				<< std::endl
			<< "\\end{tabular}" 																						<< std::endl
																														<< std::endl
			<< "\\vspace{0.3cm}" 																						<< std::endl
		;
	}
	fichier
															<< std::endl
		<< "\\newpage		" 								<< std::endl
															<< std::endl
	// --- Page 3 : Statistiques --- //
		<< "\\part*{Statistiques}" 							<< std::endl
															<< std::endl
		<< "Resultats de la simulation, temps moyen, écart-type, temps d'attente maximum atteind, somme des temps d'attente, et pourcentage des voitures ayant attendues plus d'un feu rouge." << std::endl
		<< "\\vspace{0.5cm}" 								<< std::endl
															<< std::endl
		<< "\\renewcommand\\arraystretch{1.2}" 				<< std::endl
		<< "\\begin{tabular}{|r|r|r|r|r|r|r|}" 				<< std::endl
		<< "\\hline" 										<< std::endl
		<< "\\multicolumn{1}{|c|}{\\cellcolor{lightgray} Nom de l'artère }	&" << std::endl
		<< "\\multicolumn{1}{c|}{\\cellcolor{lightgray} $ \\bar{t} $ } 		&" << std::endl
		<< "\\multicolumn{1}{c|}{\\cellcolor{lightgray} $ \\sigma{t} $ } 	&" << std::endl
		<< "\\multicolumn{1}{c|}{\\cellcolor{lightgray} $ \\max{t} $ } 		&" << std::endl
		<< "\\multicolumn{1}{c|}{\\cellcolor{lightgray} $ \\sum{t} $ }  	&" << std::endl
		<< "\\multicolumn{1}{c|}{\\cellcolor{lightgray} $ \\geq 2Feux$ } \\\\" << std::endl
	;
	// Pour chaque ResultatArtere
	itRoads=this->simulation->GetCrossroad()->roads.begin();
	for(;itRoads!=endRoads;++itRoads)
	{
		Road* artere = NetworkEngine::getInstance()->GetRoad(*itRoads);
		Result* resultat = NetworkEngine::getInstance()->GetResult(artere,this->simulation);

		fichier
			<< "\\hline" 													<< std::endl
			<< artere->GetNom()								<< "& $"
			<< secondsToTime(resultat->GetTempsMoyen()) 	<< "$ & $"
			<< secondsToTime(resultat->GetTempsEcartType()) << "$ & $"
			<< secondsToTime(resultat->GetTempsMax())		<< "$ & $"
			<< secondsToTime(resultat->GetTempsCumul())		<< "$ & $"
			<< resultat->GetDeuxFeux() 						<< "\\\%$ \\\\" << std::endl
		;
	}
	fichier
		<< "\\hline" 										<< std::endl
		<< "\\end{tabular}" 								<< std::endl
															<< std::endl
		<< "\\end{document}" 								<< std::endl
	;

	// Fermer le fichier
	fichier.close();
}

void Pdf::Generate()
{
	this->DataTotex();
	this->TexToPdf();
}

// Afficher le pdf
void Pdf::View()
{
	#if ! defined (OS_WIN) // Linux
		// commande "evince ../data/pdf/rapport.pdf"
		std::string cmd = "evince \"" + this->filePdf + "\"";
		std::system(cmd.c_str());
	#endif
	#if defined (OS_WIN) // Windobe
		std::string cmd = "\"" + this->filePdf + "\"";
		std::system(cmd.c_str());
	#endif
}

