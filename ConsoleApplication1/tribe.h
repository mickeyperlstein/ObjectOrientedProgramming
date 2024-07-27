#ifndef __TRIBE_H
#define __TRIBE_H

#include "survivor.h"

class Tribe 
{
public:


	Tribe(char* name, int max_amount) {
		setName(name);
		init(max_amount);
	}

	void setName(const char* name);
	inline char * getName() const { return this->m_name; }
	

	void addSurvivor(Survivor& newSurvivor);

	/*inline*/ Survivor** getAllSurvivors();
	/*inline*/ int getMaxSurvivors() const;
	/*inline*/ int getCurrentNumOfSurvivors() const;

	void print() const;
	void free();

private:
	
	void init(int maxSurvivors);
	Survivor**	m_allSurvivors;
	int			m_maxSurvivors;
	int			m_currentNumOfSurvivors;
	char* m_name;

};

#endif // __TRIBE_H