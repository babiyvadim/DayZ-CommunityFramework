static autoptr CF_TypeConverterConstructor g_CF_TypeConverterConstructor = null;
	
class CF_TypeConverterConstructor
{
	private void CF_TypeConverterConstructor()
	{
		CF_TypeConverter._OnCreate();
	}

	/**
	 * @note	We can safely guarantee the destructor is called on script reload, 
	 * 			we can't do the same for 'OnGameDestroy'.
	 */
	void ~CF_TypeConverterConstructor()
	{
		CF_TypeConverter._OnDestroy();
	}
		
	[CF_EventSubscriber(CF_TypeConverterConstructor._Init, CF_LifecycleEvents.OnGameCreate)]
	static void _Init()
	{
		if (g_CF_TypeConverterConstructor)
		{
			return;
		}
		
		g_CF_TypeConverterConstructor = new CF_TypeConverterConstructor();
	}

	[CF_EventSubscriber(CF_TypeConverterConstructor._Cleanup, CF_LifecycleEvents.OnGameDestroy)]
	static void _Cleanup()
	{
		g_CF_TypeConverterConstructor = null;
	}
};
