#include "survivor.h"



void Survivor::init(const char* name, int age, Survivor::eFamilyStatus status)
{
	this->setAge(age);
	this->setName(name);
	this->setStatus(status);
}

void Survivor::print() const {

}

//#include "survivor.h"
////----------------------------------------------------------------------------------------//
void Survivor::setName( const char* name )
{
	if (!isValidName(name))
	{
		cout << "The name must contain " << ( MAX_NAME_SIZE - 1 ) << " letters or less." << endl;
		return;
	}
	m_name = new char[MAX_NAME_SIZE];
	strcpy( m_name, name );
}

////----------------------------------------------------------------------------------------//
void Survivor::setAge( int age )
{
	if (age > 0 && age <= 120) {
		m_age = age;
	}
	else
		throw "Age not between 0 and 120";
}
////----------------------------------------------------------------------------------------//
//void Survivor::setStatus( Survivor::eFamilyStatus status ) 
//{
//	m_status = status;
//}
////----------------------------------------------------------------------------------------//
//const char* Survivor::getName() const
//{
//	return m_name;
//}
////----------------------------------------------------------------------------------------//
//int Survivor::getAge() const
//{
//	return m_age;
//}
////----------------------------------------------------------------------------------------//
//Survivor::eFamilyStatus Survivor::getStatus() const
//{
//	return m_status;
//}
////----------------------------------------------------------------------------------------//
//void Survivor::init( const char* name, int age, eFamilyStatus status )
//{
//	setName( name );
//	setAge( age );
//	setStatus( status );
//}
////----------------------------------------------------------------------------------------//
//void Survivor::print() const
//{
//	cout << "name: " << m_name << endl << "age: " << m_age << endl << "status: " << m_status << endl;
//}
////----------------------------------------------------------------------------------------//
