/*
 * UserDataModel.h
 *
 *  Created on: Feb. 15, 2021
 *      Author: navdeep
 */

#ifndef VIEWMODEL_PUBLIC_USERDATAMODEL_H_
#define VIEWMODEL_PUBLIC_USERDATAMODEL_H_

#include "../../Modules/common/Public/UserData.h"



class CUserDataModel:public ISession{ // @suppress("Class has a virtual method and non-virtual destructor")

private:
	SUserData *m_userDetails;
	//track the sesiion data for history
	std::list<SSessionData*> m_userSessionList;
public:
	CUserDataModel();
	CUserDataModel(SUserData* prUserData);

	//getter for user id
	long getUserId()const;
	//update for he password
	bool UpdatePassword(std::string prPasswordData);
	//update for he password
	bool UpdateUserDescription(std::string prPasswordData);
	//getter for user password
	std::string getPassword() const;

	//sessions data
	virtual bool AddSession(SSessionData *prSessionData) override;
	virtual std::list<SSessionData*> RetrieveAllSessions() override;
	virtual bool ResetSessionData() override;

};


#endif /* VIEWMODEL_PUBLIC_USERDATAMODEL_H_ */
