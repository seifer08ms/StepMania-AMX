#ifndef NetworkSyncManager_H
#define NetworkSyncManager_H
   
/*
-----------------------------------------------------------------------------
 Class: NetworkSyncManager  (And netholder)

 Desc: Uses ezsockets for primitive song syncing and score reporting.

 Copyright (c) 2003-2004 by the person(s) listed below.  All rights reserved.
	Charles Lohr
	Joshua Allen
-----------------------------------------------------------------------------
*/
 
class EzSockets;

class NetworkSyncManager 
{
public:
	NetworkSyncManager(int argc, char **argv);
	~NetworkSyncManager();

	void ReportScore(int playerID, int step, int score, int combo);	
		//If "useSMserver" then send score to server

	void ReportSongOver();	//Report to server that song is over

	void StartRequest();	//Request a start.  Block until granted.

	int Connect(char * addy, int port);
							//Connect to SM Server

	int m_playerID;  //these are currently unused, but need to stay
	int m_step;
	int m_score;
	int m_combo;
    bool useSMserver;
    EzSockets *NetPlayerClient;
    
private:
    struct netHolder		//Data structure used for sending data to server
    {
        int m_playerID;	//PID (also used for Commands)
        int m_step;		//SID (StepID, 0-6 for Miss to Marv, 7,8 for boo and ok)
        int m_score;	//Player's Score
        int m_combo;	//Player's Current Combo
    };
    
};

extern NetworkSyncManager *NSMAN;
 
#endif
 