#include "stdafx.h"
#include "ServiceModule.h"
#include "DummyServiceLib/DummyService_h.h"
#include "DummyServiceLib/DummyService.h"

class ServiceModule : public ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>
{
public:
	ServiceModule() : CAtlServiceModuleT()
	{
		m_status.dwControlsAccepted |= SERVICE_ACCEPT_SHUTDOWN;
	}

	DECLARE_LIBID(LIBID_DummyServiceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DUMMY_SERVICE, "{EB8C8791-0B95-4DE2-8818-9EA6EBFA3E4A}")

	HRESULT InitializeSecurity() throw()
	{
		// Initalize COM
        HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
		if (FAILED(hr))
		{
			return hr;
		}

		// Initialize the security DACL on the service
		return CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, 0);
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
		LogEvent(L"Run Started");
        
		m_service.Run();

		// Run the message loop
		return CAtlServiceModuleT::Run(nShowCmd);
	}

private:
	using Base = ATL::CAtlServiceModuleT<ServiceModule, IDS_SERVICE_NAME>;
	dummyservice::DummyService m_service;

} ServiceModuleObject;

extern "C" int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int nShowCmd)
{
	return ServiceModuleObject.WinMain(nShowCmd);
}
