#include "stdafx.h"
#include "ServiceModule.h"

class ServiceModule : public ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>
{
public:
	ServiceModule() : CAtlServiceModuleT()
	{
		m_status.dwControlsAccepted |= SERVICE_ACCEPT_SHUTDOWN;
	}

	//DECLARE_LIBID(LIBID_DefendpointServiceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DUMMY_SERVICE, "{21E9BB28-4990-4246-B705-64ED0A80F51B}")

	HRESULT InitializeSecurity() throw()
	{
		// TODO : Call CoInitializeSecurity and provide the appropriate security settings for the service
		return S_OK;
	}

	void OnStop()
	{
		ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>::OnStop();
	}
		
	void OnShutdown()
	{
		ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>::OnShutdown();
	}

	HRESULT Run(int nShowCmd)
	{
		return CAtlServiceModuleT::Run(nShowCmd);
	}

} ServiceObject;

/*
extern "C" int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int nShowCmd)
{
	DWORD dwReturnVal = 0;

	dwReturnVal = ServiceObject.WinMain(nShowCmd);

	return dwReturnVal;
}
*/

extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	DWORD dwReturnVal = 0;

	dwReturnVal = ServiceObject.WinMain(nShowCmd);

	return dwReturnVal;
}
