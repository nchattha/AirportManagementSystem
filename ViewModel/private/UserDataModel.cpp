/*
 * UserDataModel.cpp
 *
 *  Created on: Feb. 15, 2021
 *      Author: navdeep
 */

#include"UserDataModel.h"
#include <iostream>

using namespace std;


CUserDataModel::CUserDataModel()
	:m_userDetails(nullptr){

}

CUserDataModel::CUserDataModel(SUserData* prUserData){
	assert(prUserData!=nullptr);
	m_userDetails = prUserData;
}

long CUserDataModel::getUserId()const{
	assert(m_userDetails!=nullptr);
	assert(m_userDetails->userId!=0);
	return m_userDetails->userId;
}

bool CUserDataModel::UpdatePassword(std::string prPasswordData){
	assert(m_userDetails!= nullptr);

	PasswordValidator::EValidatorMssg passwordValidatorMssg = PasswordValidator::CPasswordValidator::Validate(prPasswordData);
	switch(passwordValidatorMssg)
	{
	case PasswordValidator::EValidatorMssg::None:
		m_userDetails->password = prPasswordData;
		return true;
	case PasswordValidator::EValidatorMssg::Strong:
		std::cout<<"Password Not Strong"<<std::endl;
		break;
	case PasswordValidator::EValidatorMssg::Moderate:
			std::cout<<"Password is Moderate"<<std::endl;
			break;
	case PasswordValidator::EValidatorMssg::Weak:
			std::cout<<"Password is Weak"<<std::endl;
			break;
	case PasswordValidator::EValidatorMssg::LengthError:
			std::cout<<"Password Need to be %d -"<<PasswordValidator::CPasswordValidator::MIN_SIZE<<
			" %d "<<PasswordValidator::CPasswordValidator::MAX_SIZE<<" characters"<<std::endl;
			break;
	default:{}
	}
	return false;
}

bool CUserDataModel::UpdateUserDescription(std::string prDescriptionData){
	assert(m_userDetails!= nullptr);

	if( !prDescriptionData.empty())
	{
		m_userDetails->userDescription = prDescriptionData;
		return true;
	}

	return false;
}

std::string CUserDataModel::getPassword() const{
	assert(m_userDetails!= nullptr);
	return m_userDetails->password;
}

bool CUserDataModel::AddSession(SSessionData *prSessionData){
	if( prSessionData != nullptr)
	{
		m_userSessionList.push_back(prSessionData);
		return true;
	}
	return false;
}

std::list<SSessionData*> CUserDataModel::RetrieveAllSessions() {
	assert(m_userSessionList.size()==0);
	return m_userSessionList;
}

bool CUserDataModel::ResetSessionData() {
	assert(m_userSessionList.size()==0);
	m_userSessionList.clear();
	return true;
}


