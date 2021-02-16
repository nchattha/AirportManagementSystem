/*
 * UserData.h
 *
 *  Created on: Jan. 10, 2021
 *      Author: navdeep
 */

#ifndef COMMON_PUBLIC_USERDATA_H_
#define COMMON_PUBLIC_USERDATA_H_
#include <ctime>
#include <string>
#include <list>
#include <cassert>
#include <ctype.h>
typedef enum UserType{
	Admin,
	AirportOperations,
	ATController,
	FlightOperations,
	CustomerServices,
}EUserType;

//SESSION DATA STARTS
typedef struct SessionData{
	std::time_t logTime;
	std::time_t prevSessionTime;
	std::time_t inactiveTimeoutTime;
}SSessionData;

class ISession{ // @suppress("Class has a virtual method and non-virtual destructor")
public:
		virtual bool AddSession(SSessionData *prSessionData)=0;
		virtual std::list<SSessionData*> RetrieveAllSessions()=0;
		virtual bool ResetSessionData()=0;
};
//SESSION DATA ENDS

//PASSWORD CHECKER STARTS
namespace PasswordValidator{
typedef enum ValidatorMssg{
	Strong,
	Weak,
	Moderate,
	LengthError,
	Unfit,
	None
}EValidatorMssg;

class CPasswordValidator{
public:
	static const int MAX_SIZE = 32; //Array Size
	static const int MIN_SIZE = 6; //Array Size
	static EValidatorMssg Validate(std::string &prPasswordData){

		int l_case=0, u_case=0, digit=0, special=0;
		int l=prPasswordData.length(),i;

		if( l >= MIN_SIZE && l < MAX_SIZE )
			return EValidatorMssg::Unfit;

		char char_array[l + 1];
		strcpy(char_array, prPasswordData.c_str());


		  for(i=0;i<l;i++)
		  {
		    if( islower(char_array[i]))
		      l_case=1;
		    if(isupper(char_array[i]))
		      u_case=1;
		    if(isdigit(char_array[i]))
		      digit=1;
		    if(!isalpha(char_array[i]) && !isdigit(char_array[i]))
		      special=1;
		  }

		  if(l_case && u_case && digit && special && l>=8)
		    return EValidatorMssg::Strong;
		  else if((l_case+u_case+digit+special>=3) && l>=6)
		    return EValidatorMssg::Moderate;
		  else
		    return EValidatorMssg::Weak;

		  return EValidatorMssg::None;
	}
};
}
//PASSWORD CHECKER ENDS

typedef struct UserData{
	//need to be unique user id
	long userId;
	// password can be alphanumeric
	std::string password;
	//user can have single category associated to user ID
	EUserType userCategory;
	//user description
	std::string userDescription;
}SUserData;


#endif /* COMMON_PUBLIC_USERDATA_H_ */
