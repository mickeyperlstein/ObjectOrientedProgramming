#ifndef __SURVIVORS_H
#define __SURVIVORS_H

#include <iostream>
#include <string.h>
using namespace std;
#include <cctype> // For std::isalnum

#pragma warning(disable: 4996)

class Survivor
{
public:

	enum eFamilyStatus { SINGLE, MARRIED, IN_A_RELATIONSHIP };
	static const int MAX_NAME_SIZE = 21;

public:
	
	Survivor(const char* name, int age,  eFamilyStatus status) {
		setName(name);
		setAge(age);
		setStatus(status);
	}

	inline void setName(const char* name);
	
	static bool isValidName(const char* name)
	{
		
		return 
			isValidNameLen(name) &&
			isValidAlphanumericName(name);
	}

	//as a cpp CS Student, write an bool isValidAlphanumericName(char* name) function
	//	ChatGPT

	static bool isValidAlphanumericName(const char* name) {
		if (name == nullptr || name[0] == '\0') {
			return false;  // Empty or null name is not valid
		}

		int i = 0;
		while (name[i] != '\0') {
			char c = name[i];
			bool isAlphanumeric = (c >= 'A' && c <= 'Z') ||
				(c >= 'a' && c <= 'z') ||
				(c >= '0' && c <= '9');

			if (!isAlphanumeric) {
				return false;
			}

			i++;
		}
		return true;
	}
	
	static bool isValidNameLen(const char* name) {
		return strlen(name) <= MAX_NAME_SIZE;
	}

	const char* getName() const { return this->m_name; }

	inline void setAge(int age);
	inline int getAge() const { return this->m_age; }

	void setStatus(eFamilyStatus status) { this->m_status = status;  }
	eFamilyStatus getStatus() const { return this->m_status; }

	void init(const char* name, int age, eFamilyStatus status);
	void print() const;

private:
	char * 			m_name;
	int				m_age;
	eFamilyStatus	m_status;
};

#endif // __SURVIVORS_H
//#ifndef __SURVIVORS_H
//#define __SURVIVORS_H
//
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//#pragma warning(disable: 4996)
//
//class Survivor
//{
//public:
//	enum eFamilyStatus { SINGLE, MARRIED, IN_A_RELATIONSHIP };
//	static const int MAX_NAME_SIZE = 21;
//
//public:
//	inline void setName( const char* name );
//	inline void setAge( int age );
//	inline void setStatus( eFamilyStatus status );
//
//	inline const char* getName() const;
//	inline int getAge() const;
//	inline eFamilyStatus getStatus() const;
//
//	void init( const char* name, int age, eFamilyStatus status );
//	void print() const;
//
//private:
//	char			m_name[MAX_NAME_SIZE];
//	int				m_age;
//	eFamilyStatus	m_status;
//};
//
//#endif // __SURVIVORS_H

bool isValidName(const char* name);
