#include "pch.h"
#include "myconnectorclassDB.h"
#include <vector>
#include <string.h>

myconnectorclassDB::myconnectorclassDB()
{
}

myconnectorclassDB::~myconnectorclassDB()
{
}

void myconnectorclassDB::connect()
{
	connection = mysql_init(NULL); //Initialise the instance
	connection = mysql_real_connect(connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
	// The command mysql_real_connect is included in the
	// libraries
	if (connection) {
		// Add debug code here
	}
	else {
		// and here
	}
}

std::vector<CString> myconnectorclassDB::CheckLogin(CString logintype, CString inputedname)
{
	CString value; // Create the object to receive the answer to the query
	CString query;

	if (logintype != "sd")
		query = _T("SELECT ") + logintype + _T("_name,pass FROM ") + logintype + _T(" WHERE ") + logintype + _T(".") + logintype + _T("_name = '") + inputedname + _T("'");
	else
		query = _T("SELECT sd_name,pass FROM sporting_director WHERE sporting_director.sd_name = '") + inputedname + _T("'");
		
	Query(query); 

	row = mysql_fetch_row(result);

	std::vector<CString> logininfo;
	int line = 0;
	int ncolumns = 2;
	
	if (row != NULL)
	{
		for (int i = 0; i < ncolumns; i++)
		{
			logininfo.push_back(CPtoUnicode(row[i], 1251));
		}
	}
	
    return logininfo;
}


void myconnectorclassDB::Query(CString query)
{
	wchar_t* p = query.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8, sizeof(bufUTF8), NULL, NULL);

	mysql_query(connection, bufUTF8); //Send a query
	result = mysql_store_result(connection); //Store the result
}

CString myconnectorclassDB::CPtoUnicode(const char* CPString, UINT CodePage)
{
	CString retValue;
	int len = MultiByteToWideChar(CodePage, 0, CPString, -1, NULL, 0);
	if (len == 0) { return retValue; }
	LPWSTR buffer = retValue.GetBuffer(len);
	MultiByteToWideChar(CodePage, 0, CPString, -1, buffer, len);
	retValue.ReleaseBuffer();
	return retValue;
}

/*Funções Zé Charles*/
vector<LVITEM> myconnectorclassDB::getPlayerInfo(CString  requirement) {
	
	
	CString init_query=_T("CALL init_query()");
	Query(init_query);
	connect();
	CString  query = requirement;
	vector<LVITEM> search_results;
	Query(query);
	int numrows = mysql_num_rows(result);
	int numcols = mysql_num_fields(result);
	int nentries = numrows * numcols;
	static vector<CString> query_disp_value(1000);
	int line = 0;
	int value_index = 0;
	if (result != NULL) {
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			for (int i = 0; i < numcols; i++) {
				query_disp_value[value_index] = CPtoUnicode(row[i], 1251);
				LVITEM lvi;
				lvi.mask = LVIF_TEXT;
				lvi.iItem = line;
				lvi.iSubItem = i;
				lvi.pszText = (LPTSTR)(LPCTSTR)(query_disp_value[value_index]);
				search_results.push_back(lvi);
				value_index++;
			}
			line++;
		}
	}
	return search_results;
	query_disp_value.clear();	
}



float myconnectorclassDB::Checkgoalkeeper_rating(CString player_name_in)
{
	CString value_str;
	float value;
	CString query = _T("CALL gk_rating('") + player_name_in + _T("')");
	Query(query);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		value_str = CPtoUnicode(row[0], 1251);
	}
	value = _ttof(value_str);
	return value;
}

float myconnectorclassDB::Checktechnical_rating(CString player_name_in)
{
	CString value_str;
	float value;
	CString query = _T("CALL tech_rating('") + player_name_in + _T("')");
	Query(query);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		value_str = CPtoUnicode(row[0], 1251);
	}
	value = _ttof(value_str);
	return value;
}

float myconnectorclassDB::Checkmental_rating(CString player_name_in)
{
	CString value_str;
	float value;
	CString query = _T("CALL ment_rating('") + player_name_in + _T("')");
	Query(query);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		value_str = CPtoUnicode(row[0], 1251);
	}
	value = _ttof(value_str);
	return value;
}

float myconnectorclassDB::Checkphysical_rating(CString player_name_in)
{
	CString value_str;
	float value;
	CString query = _T("CALL phys_rating('") + player_name_in + _T("')");
	Query(query);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		value_str = CPtoUnicode(row[0], 1251);
	}
	value = _ttof(value_str);
	return value;
}

vector<CString> myconnectorclassDB::getSCInfo(CString player_name_in)
{
	CString query = _T("CALL sc_report_info('") + player_name_in + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	vector<CString> sc_report;
	int line = 0; int ncolumns = 11;
	for (int i = 0; i < ncolumns; i++) {
		sc_report.push_back(CPtoUnicode(row[i], 1251));
	}
	return sc_report;
}

vector<CString> myconnectorclassDB::getFinancialInfo(CString player_name_in)
{
	CString query = _T("CALL financial_info('") + player_name_in + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	vector<CString> financial_info;
	int line = 0; int ncolumns = 6;
	for (int i = 0; i < ncolumns; i++) {
		financial_info.push_back(CPtoUnicode(row[i], 1251));
	}
	return financial_info;
}

vector<CString> myconnectorclassDB::getAgentInfo(CString player_name_in)
{
	CString query = _T("CALL agent_info('") + player_name_in + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	vector<CString> agent_info;
	int line = 0; int ncolumns = 5;
	for (int i = 0; i < ncolumns; i++) {
		agent_info.push_back(CPtoUnicode(row[i], 1251));
	}
	return agent_info;
}


vector<CString> myconnectorclassDB::getBioInfo(CString player_name_in)
{
	CString query = _T("CALL bio_info('") + player_name_in + _T("')");
	Query(query);
	//int value = 0;
	row = mysql_fetch_row(result);
	vector<CString> bio_info;
	int line = 0; int ncolumns = 8;
	for (int i = 0; i < ncolumns; i++) {
		bio_info.push_back(CPtoUnicode(row[i], 1251));
		/*AfxMessageBox(bio_info[value]);
		value++;*/
	}
	return bio_info;
}

void myconnectorclassDB::referplayer(CString coach_name, CString sd_name, CString player_name_in)
{

	CString query = _T("CALL addnewrefers_to('") + coach_name + _T("','") + sd_name + _T("','") + player_name_in + _T("')");
	Query(query);

}

CString myconnectorclassDB::CheckPlayer(CString pname)
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT player.player_name FROM player WHERE player.player_name = '") + pname + _T("'");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) // Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}

	return value;
}


void myconnectorclassDB::createplayer(CString np_name, CString np_pos, CString np_club, CString np_bd, CString np_df, CString np_coun, CString np_hght, CString np_wght, CString np_ic)
{
	CString query = _T("CALL addnewplayer('") + np_name + _T("','") + np_pos + _T("','") + np_club + _T("','") + np_bd + _T("','") + np_df + _T("','") + np_coun + _T("','") + np_hght + _T("','") + np_wght + _T("','") + np_ic + _T("')");
	Query(query);
}


CString myconnectorclassDB::getsdname(CString coach_name_in)
{
	CString sd_name;
	CString query = _T("CALL get_sd_name('")+coach_name_in+_T("')");
	Query(query);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		sd_name = CPtoUnicode(row[0], 1251);
	}
	return sd_name;
}


CString myconnectorclassDB::getcoachname(CString sd_name_in)
{
	CString coach_name;
	CString query = _T("CALL get_coach_name('") + sd_name_in + _T("')");
	Query(query);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		coach_name = CPtoUnicode(row[0], 1251);
	}
	return coach_name;
}


vector<LVITEM> myconnectorclassDB::getRefdPlayer(CString sd_name) {

	CString  query = _T("CALL reffromcoach('") + sd_name + _T("')");
	vector<LVITEM> search_results;
	Query(query);
	int numrows = mysql_num_rows(result);
	int numcols = mysql_num_fields(result);
	int nentries = numrows * numcols;
	static vector<CString> query_disp_value(1000);
	int line = 0;
	int value_index = 0;
	if (result != NULL) {
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			for (int i = 0; i < numcols; i++) {
				query_disp_value[value_index] = CPtoUnicode(row[i], 1251);
				LVITEM lvi;
				lvi.mask = LVIF_TEXT;
				lvi.iItem = line;
				lvi.iSubItem = i;
				lvi.pszText = (LPTSTR)(LPCTSTR)(query_disp_value[value_index]);
				search_results.push_back(lvi);
				value_index++;
			}
			line++;
		}
	}
	return search_results;
	query_disp_value.clear();
}

vector<CString> myconnectorclassDB::getscoutvector()
{
	CString query = _T("CALL getscoutvector()");
	Query(query);
	vector<CString> scoutvectort;
	if (result != NULL) {
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			scoutvectort.push_back(CPtoUnicode(row[0], 1251));
		
		}
	}
	return scoutvectort;
}

void myconnectorclassDB::newrequest(CString position, CString coach_name, CString scout_name, CString p_requirements)
{
	CString query = _T("CALL addnewrequest('") + position + _T("','") + coach_name + _T("','")+scout_name+ _T("','") + p_requirements + _T("')");
	Query(query);
}

vector<LVITEM> myconnectorclassDB::getrequests(CString scout_name_in)
{
	CString query = _T("CALL getrequests('") + scout_name_in + _T("')");
	vector<LVITEM> requests;
	Query(query);
	int numrows = mysql_num_rows(result);
	int numcols = mysql_num_fields(result);
	int nentries = numrows * numcols;
	static vector<CString> query_disp_value(1000);
	int line = 0;
	int value_index = 0;
	if (result != NULL) {
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			for (int i = 0; i < numcols; i++) {
				query_disp_value[value_index] = CPtoUnicode(row[i], 1251);
				LVITEM lvi;
				lvi.mask = LVIF_TEXT;
				lvi.iItem = line;
				lvi.iSubItem = i;
				lvi.pszText = (LPTSTR)(LPCTSTR)(query_disp_value[value_index]);
				requests.push_back(lvi);
				value_index++;
			}
			line++;
		}
	}
	return requests;
	query_disp_value.clear();
}

void myconnectorclassDB::dropi()
{
	CString query = _T("DROP TABLE  if exists i");
	Query(query);

}

//Queries Cotrim
//Check if player exsts
CString myconnectorclassDB::CheckPlayerBC(CString pname)
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT player.player_name FROM player WHERE player.player_name = '") + pname + _T("'");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) // Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}

	return value;
}


//Add new player personal info
void myconnectorclassDB::createplayerBC(CString np_name, CString np_pos, CString np_club, CString np_bd, CString np_df, CString np_coun, CString np_hght, CString np_wght, CString np_ic)
{
	CString query = _T("CALL addnewplayer('") + np_name + _T("','") + np_pos + _T("','") + np_club + _T("','") + np_bd + _T("','") + np_df + _T("','") + np_coun + _T("','") + np_hght + _T("','") + np_wght + _T("','") + np_ic + _T("')");
	Query(query);
}


//Obtain personal info
std::vector<CString> myconnectorclassDB::getPersnalInfoBC(CString player_name_in)
{
	CString query = _T("CALL bio_info('") + player_name_in + _T("')");
	Query(query);

	row = mysql_fetch_row(result);

	std::vector<CString> player_info;

	int line = 0;
	int ncolumns = 8;

	for (int i = 0; i < ncolumns; i++)
	{
		player_info.push_back(CPtoUnicode(row[i], 1251));
	}
	return player_info;
}


//Obtain scouting report
std::vector<CString> myconnectorclassDB::getSCInfoBC(CString player_name_in)
{
	CString query = _T("CALL sc_report_info('") + player_name_in + _T("')");
	Query(query);

	row = mysql_fetch_row(result);

	std::vector<CString> sc_report;

	int line = 0;
	int ncolumns = 11;

	if (row != NULL)
	{
		for (int i = 0; i < ncolumns; i++)
		{
			sc_report.push_back(CPtoUnicode(row[i], 1251));
		}
	}

	return sc_report;
}


//Obtain scouting report
std::vector<CString> myconnectorclassDB::getPlayerScoutBC(CString player_name_in)
{
	CString query = _T("CALL getplayerscout('") + player_name_in + _T("')");
	Query(query);

	row = mysql_fetch_row(result);

	std::vector<CString> scout;

	int line = 0;
	int ncolumns = 3;

	if (row != NULL)
	{
		for (int i = 0; i < ncolumns; i++)
		{
			scout.push_back(CPtoUnicode(row[i], 1251));
		}
	}

	return scout;
}


//Obtain financial info
std::vector<CString> myconnectorclassDB::getFinInfoBC(CString player_name_in)
{
	CString query = _T("CALL financial_info('") + player_name_in + _T("')");
	Query(query);

	row = mysql_fetch_row(result);

	std::vector<CString> financial;

	int line = 0;
	int ncolumns = 6;

	if (row != NULL)
	{
		for (int i = 0; i < ncolumns; i++)
		{
			financial.push_back(CPtoUnicode(row[i], 1251));
		}
	}

	return financial;
}


//Obtain financial info
std::vector<CString> myconnectorclassDB::getAgentInfoBC(CString player_name_in)
{
	CString query = _T("CALL agent_info('") + player_name_in + _T("')");
	Query(query);
	row = mysql_fetch_row(result);

	std::vector<CString> value;

	int line = 0; int ncolumns = 5;

	if (row != NULL)
	{
		for (int i = 0; i < ncolumns; i++)
		{
			value.push_back(CPtoUnicode(row[i], 1251));
		}
	}

	return value;
}


//Obtain last scouting report
CString myconnectorclassDB::GetLastScoutReportBC()
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT MAX(report_id) FROM watches");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) // Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}

	return value;
}


//Obtain last contract ID
CString myconnectorclassDB::GetLastContractBC()
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT MAX(contract_id) FROM provides");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) // Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}

	return value;
}


//Add new scout report
void myconnectorclassDB::AddScoutReportBC(CString scout_name_in, CString nextreport_id, CString player_name_in)
{
	CString query = _T("CALL addnewscreport (") + nextreport_id + _T(",0,0,0,0,0,0,0,0,0,0,0)");
	Query(query);
	connect();

	query = _T("CALL addnewwatches('") + scout_name_in + _T("','") + nextreport_id + _T("','") + player_name_in + _T("')");
	Query(query);
}


//Add new contract
void myconnectorclassDB::AddNewContractBC(CString agent_name_in, CString nextcontract_id, CString player_name_in)
{
	CString query = _T("CALL addnewfinancialinfo('") + nextcontract_id + _T("','2100-12-31','0','0','1','1','0')");
	Query(query);
	connect();

	query = _T("CALL addnewprovides('") + agent_name_in + _T("','") + nextcontract_id + _T("','") + player_name_in + _T("','0')");
	Query(query);
}


//Edit personal info
void myconnectorclassDB::EditPersonalInfo(CString np_name, CString np_pos, CString np_club, CString np_bd, CString np_df, CString np_coun, CString np_hght, CString np_wght, CString np_ic)
{
	CString query = _T("CALL editplayer('") + np_name + _T("','") + np_pos + _T("','") + np_club + _T("','") + np_bd + _T("','") + np_df + _T("','") + np_coun + _T("','") + np_hght + _T("','") + np_wght + _T("','") + np_ic + _T("')");
	Query(query);
}


//Edit personal info
void myconnectorclassDB::EditScoutingReport(CString report_id, CString ep_hand, CString ep_ref, CString ep_shot, CString ep_pass, CString ep_tack, CString ep_drib, CString ep_lead, CString ep_pos, CString ep_stgh, CString ep_stam, CString ep_spd)
{
	CString query = _T("CALL editscreport('") + report_id + _T("','") + ep_hand + _T("','") + ep_ref + _T("','") + ep_shot + _T("','") + ep_pass + _T("','") + ep_tack + _T("','") + ep_drib + _T("','") + ep_lead + _T("','") + ep_pos + _T("','") + ep_stgh + _T("','") + ep_stam + _T("','") + ep_spd + _T("')");
	Query(query);
}


//Edit financial report
void myconnectorclassDB::EditFinancialInfo(CString ins_contract_id, CString ins_contract_exp, CString ins_transf_fee, CString ins_current_wage, CString ins_demanded_wage, CString ins_demand_contract_l, CString ins_sig_fee, CString ins_age_fee)
{
	CString query = _T("CALL editfinancialinfo('") + ins_contract_id + _T("','") + ins_contract_exp + _T("','") + ins_transf_fee + _T("','") + ins_current_wage + _T("','") + ins_demanded_wage + _T("','") + ins_demand_contract_l + _T("','") + ins_sig_fee + _T("')");
	Query(query);
	connect();

	query = _T("CALL editagentfee('") + ins_contract_id + _T("','") + ins_age_fee + _T("')");
	Query(query);
}


//Obtain last scouting report
CString myconnectorclassDB::GetPlayerScoutReportBC(CString player_name_in)
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT report_id FROM watches WHERE player_name = '") + player_name_in + _T("'");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) // Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}

	return value;
}


//Obtain last contract ID
CString myconnectorclassDB::GetPlayerContractBC(CString player_name_in)
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT contract_id FROM provides WHERE player_name = '") + player_name_in + _T("'");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) // Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}

	return value;
}