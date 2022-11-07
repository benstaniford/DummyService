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

	void OnStop();
	void OnShutdown();

	HRESULT Run(int nShowCmd);

private:
	HANDLE m_hThread = nullptr;

} ServiceObject;

extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return ServiceObject.WinMain(nShowCmd);
}
