#include "stdafx.h"
#include "ServiceModule.h"

class ServiceModule : public ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>
{
public:
	ServiceModule() : CAtlServiceModuleT()
	{
		m_status.dwControlsAccepted |= SERVICE_ACCEPT_SHUTDOWN;
	}

	//DECLARE_LIBID(LIBID_DummyServiceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DUMMY_SERVICE, "{EB8C8791-0B95-4DE2-8818-9EA6EBFA3E4A}")

	HRESULT InitializeSecurity() throw()
	{
		// TODO : Call CoInitializeSecurity and provide the appropriate security settings for the service
		return S_OK;
	}

	void OnStop()
	{
		Base::OnStop();
	}
		
	void OnShutdown()
	{
		Base::OnShutdown();
	}

	HRESULT Run(int nShowCmd)
	{
		return CAtlServiceModuleT::Run(nShowCmd);
	}

private:
	using Base = ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>;

} ServiceObject;

extern "C" int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int nShowCmd)
{
	return ServiceObject.WinMain(nShowCmd);
}
