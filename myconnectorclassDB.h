#pragma once

//#include "myglobal.h"
#include "mysql.h"
#include "atlstr.h"
#include <vector>

using namespace std;

class myconnectorclassDB
{
private:
	#define SERVER "db.tecnico.ulisboa.pt"
	#define USER "ist187225"// Your IST number
	#define PASSWORD "invf3798" // NOT IST password
	#define DATABASE "ist187225" // Your IST number
	
	void Query(CString query); // Main query function
	MYSQL *connection; // Pointer allocation for a connection
	// This is an object creation of an existing class in
	// the mySQL libraries we added.

public:
	MYSQL_ROW row; // Another object based on the existing
	// library, this one stores a single row from queries
	MYSQL_RES *result; // and this one the entire result
	// from a query
	void connect(); // Connection function. Notice how
	// this is public, but the connection itself is
	// private.
	CString CPtoUnicode(const char* CPString, UINT CodePage);
	// Converts data from MySQL format to MFC's CString.
	// My Queries
	vector<CString> CheckLogin(CString logintype, CString inputedname);
	vector<LVITEM> getPlayerInfo(CString requirement);
	float Checkgoalkeeper_rating(CString player_name_in);
	float Checktechnical_rating(CString player_name_in);
	float Checkmental_rating(CString player_name_in);
	float Checkphysical_rating(CString player_name_in);
	vector<CString> getSCInfo(CString player_name_in);
	vector<CString> getFinancialInfo(CString player_name_in);
	vector<CString> getAgentInfo(CString player_name_in);
	vector<CString> getBioInfo(CString player_name_in);
	void referplayer(CString player_name_in, CString coach_name, CString sd_name);
	CString CheckPlayer(CString pname);
	void createplayer(CString np_name, CString np_pos, CString np_club, CString np_bd, CString np_df, CString np_coun, CString np_hght, CString np_wght, CString np_ic);
	CString getsdname(CString coach_name);
	CString getcoachname(CString sd_name_in);
	vector<LVITEM> getRefdPlayer(CString sd_name);
	vector<CString> getscoutvector();
	void newrequest(CString position, CString coach_name, CString scout_name, CString p_requirements);
	vector<LVITEM> getrequests(CString scout_name_in);
	void dropi();
	CString CheckPlayerBC(CString pname);
	vector<CString> getPersnalInfoBC(CString player_name_in);
	vector<CString> getSCInfoBC(CString player_name_in);
	vector<CString> getFinInfoBC(CString player_name_in);
	vector<CString> getAgentInfoBC(CString player_name_in);
	vector<CString> getPlayerScoutBC(CString player_name_in);
	CString GetLastScoutReportBC();
	CString GetLastContractBC();
	void createplayerBC(CString np_name, CString np_pos, CString np_club, CString np_bd, CString np_df, CString np_coun, CString np_hght, CString np_wght, CString np_ic);
	void AddScoutReportBC(CString scout_name_in, CString nextreport_id, CString player_name_in);
	void AddNewContractBC(CString agent_name_in, CString nextcontract_id, CString player_name_in);
	void EditPersonalInfo(CString np_name, CString np_pos, CString np_club, CString np_bd, CString np_df, CString np_coun, CString np_hght, CString np_wght, CString np_ic);
	void EditScoutingReport(CString report_id, CString ep_hand, CString ep_ref, CString ep_shot, CString ep_pass, CString ep_tack, CString ep_drib, CString ep_lead, CString ep_pos, CString ep_stgh, CString ep_stam, CString ep_spd);
	void EditFinancialInfo(CString ins_contract_id, CString ins_contract_exp, CString ins_transf_fee, CString ins_current_wage, CString ins_demanded_wage, CString ins_demand_contract_l, CString ins_sig_fee, CString ins_age_fee);
	CString GetPlayerScoutReportBC(CString player_name_in);
	CString GetPlayerContractBC(CString player_name_in);
	myconnectorclassDB(void);
	virtual ~myconnectorclassDB(void);
};

