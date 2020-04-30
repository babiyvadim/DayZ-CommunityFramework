class JMModuleBase
{
	protected bool m_Enabled;
	protected bool m_PreventInput;
	protected ref set< ref JMModuleBinding > m_Bindings;
	
	void JMModuleBase()
	{
		m_Enabled = true;
		m_PreventInput = false;
		m_Bindings = new set< ref JMModuleBinding >;
	}
	
	void ~JMModuleBase()
	{
	}
	
	void Init()
	{
		RegisterKeyMouseBindings();
	}

	void Toggle()
	{
		m_Enabled = !m_Enabled;
	}

	void PreventInput(bool prevent)
	{
		m_PreventInput = prevent;
	}

	string GetModuleName()
	{
		return ClassName();
	}

	typename GetModuleType()
	{
		return GetModuleName().ToType();
	}

	bool IsEnabled()
	{
		return m_Enabled;
	}

	bool IsPreventingInput()
	{
		return m_PreventInput;
	}

	/**
	 * Can't change dynamically, only used on module init, if false 
	 * and is mission host, the module is destroyed and forgotten.
	 */
	bool IsServer()
	{
		return true;
	}

	/**
	 * Can't change dynamically, only used on module init, if false 
	 * and is mission client, the module is destroyed and forgotten.
	 */
	bool IsClient()
	{
		return true;
	}

	void RegisterKeyMouseBindings() 
	{
	}
	
	/**
	 * Deprecated, use RegisterBinding instead.
	 */
	void RegisterKeyMouseBinding( JMModuleBinding binding ) 
	{
		RegisterBinding( binding );
		Error( GetModuleName() + "::RegisterKeyMouseBinding has been deprecated, use " + GetModuleName() + "::RegisterBinding instead." );
	}

	void RegisterBinding( JMModuleBinding binding ) 
	{
		m_Bindings.Insert( binding );
	}
	
	set< ref JMModuleBinding > GetBindings()
	{
		return m_Bindings;
	}

	// Events 

	/**
	 * Is called every mission frame
	 * 
	 * @timeslice time of previous update
	 */
	void OnUpdate( float timeslice ) 
	{
	}

	void OnSettingsUpdated()
	{
	}

	void OnInit()
	{
	}
	
	void OnMissionStart()
	{
	}
	
	void OnMissionFinish()
	{
	}
	
	void OnMissionLoaded()
	{
	}

	void OnRPC( PlayerIdentity sender, Object target, int rpc_type, ref ParamsReadContext ctx )
	{
	}

	int GetRPCMin()
	{
		return -1;
	}

	int GetRPCMax()
	{
		return -1;
	}

	/**
	 * @brief See: WorldCleaupEventTypeID
	 */
	bool OnWorldCleanup()
	{
		return false;
	}

	/**
	 * @brief See: MPSessionStartEventTypeID
	 */
	bool OnMPSessionStart()
	{
		return false;
	}

	/**
	 * @brief See: MPSessionPlayerReadyEventTypeID
	 */
	bool OnMPSessionPlayerReady()
	{
		return false;
	}

	/**
	 * @brief See: MPSessionFailEventTypeID
	 */
	bool OnMPSessionFail()
	{
		return false;
	}

	/**
	 * @brief See: MPSessionEndEventTypeID
	 */
	bool OnMPSessionEnd()
	{
		return false;
	}

	/**
	 * @brief See: ConnectingAbortEventTypeID
	 */
	bool OnMPConnectAbort()
	{
		return false;
	}

	/**
	 * @brief See: MPConnectionLostEventTypeID
	 */
	bool OnMPConnectionLost( int duration )
	{
		return false;
	}

	/**
	 * @brief See: RespawnEventTypeID
	 */
	bool OnRespawn( int time )
	{
		return false;
	}

	/**
	 * @brief See: LogoutCancelEventTypeID
	 */
	bool OnClientLogoutCancelled( PlayerBase player, PlayerIdentity identity )
	{
		return false;
	}

	/**
	 * @brief See: MissionServer::InvokeOnConnect
	 */
	bool OnInvokeConnect( PlayerBase player, PlayerIdentity identity )
	{
		return false;
	}

	/**
	 * @brief See: MissionServer::InvokeOnDisconnect
	 */
	bool OnInvokeDisconnect( PlayerBase player )
	{
		return false;
	}

	/**
	 * @brief See: ClientNewEventTypeID
	 */
	bool OnClientNew( out PlayerBase player, PlayerIdentity identity, vector pos, ParamsReadContext ctx )
	{
		return false;
	}

	/**
	 * @brief See: ClientRespawnEventTypeID
	 */
	bool OnClientRespawn( PlayerBase player, PlayerIdentity identity )
	{
		return false;
	}

	/**
	 * @brief See: ClientReadyEventTypeID
	 */
	bool OnClientReady( PlayerBase player, PlayerIdentity identity )
	{
		return false;
	}

	/**
	 * @brief See: ClientPrepareEventTypeID
	 */
	bool OnClientPrepare( PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout )
	{
		return false;
	}

	/**
	 * @brief See: ClientReconnectEventTypeID
	 */
	bool OnClientReconnect( PlayerBase player, PlayerIdentity identity )
	{
		return false;
	}

	/**
	 * @brief See: ClientDisconnectedEventTypeID
	 */
	bool OnClientLogout( PlayerBase player, PlayerIdentity identity, int logoutTime, bool authFailed )
	{
		return false;
	}

	/**
	 * @brief See: MissionServer::PlayerDisconnected - Fires when the player has disconnected from the server (OnClientReconnect won't fire)
	 */
	bool OnClientDisconnect( PlayerBase player, PlayerIdentity identity, string uid )
	{
		return false;
	}

	/**
	 * @brief See: LogoutCancelEventTypeID
	 */
	bool OnClientLogoutCancelled( PlayerBase player )
	{
		return false;
	}
}
