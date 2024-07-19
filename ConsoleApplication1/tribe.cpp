#include "tribe.h"
//----------------------------------------------------------------------------------------//
void Tribe::init( int maxSurvivors )
{
	m_maxSurvivors = maxSurvivors;
	m_currentNumOfSurvivors = 0;
	m_allSurvivors = new Survivor*[m_maxSurvivors];
}
//----------------------------------------------------------------------------------------//
bool Tribe::addSurvivor( Survivor& newSurvivor )
{
	if( m_currentNumOfSurvivors < m_maxSurvivors )
	{
		m_allSurvivors[m_currentNumOfSurvivors++] = &newSurvivor;
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------------------//
Survivor** Tribe::getAllSurvivors()
{
	return m_allSurvivors;
}
//----------------------------------------------------------------------------------------//
int Tribe::getCurrentNumOfSurvivors() const
{
	return m_currentNumOfSurvivors;
}
//----------------------------------------------------------------------------------------//
int Tribe::getMaxSurvivors() const
{
	return m_maxSurvivors;
}
//----------------------------------------------------------------------------------------//
void Tribe::print() const
{
	for( int i = 0; i < m_currentNumOfSurvivors; ++i )
		m_allSurvivors[i]->print();
}
//----------------------------------------------------------------------------------------//
void Tribe::free()
{
	for( int i = 0; i < m_currentNumOfSurvivors; ++i )
		delete m_allSurvivors[i];

	delete[] m_allSurvivors;
}
//----------------------------------------------------------------------------------------//