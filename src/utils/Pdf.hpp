/*
 * Pdf.hpp
 *
 *  Created on: 26 avr. 2011
 *      Author: Axel GUILMIN
 */

#ifndef PDF_HPP_
#define PDF_HPP_

#include "../entities/entitiesList.hpp"
#include "library.hpp"
#include "../network/NetworkEngine.hpp"


// Saovoir si on compile sous windows
#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
	#define OS_WIN
#endif

class Pdf
{
public :
	Pdf(Simulation* simulation);
	~Pdf();
	void Generate();
	void View();

private :
	std::string fileTex;
	std::string fileAux;
	std::string fileLog;
	std::string filePdf;

	Simulation* simulation;

	void DataTotex();
	void TexToPdf();
};


#endif /* PDF_HPP_ */
