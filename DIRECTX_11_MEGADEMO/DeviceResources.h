#pragma once
#include "common.h"
#include "debug.h"

using namespace Microsoft::WRL;

class DeviceResources
{
public:
	DeviceResources();
	// ������� Direct3d
	ComPtr<ID3D11Device2> device;
	ComPtr<ID3D11DeviceContext2> devcon;
	ComPtr<IDXGISwapChain1> swapChain;
	// ������� ��� ���������� ���������
	ComPtr<ID3D11RenderTargetView> renderTargetView;
	ComPtr<ID3D11DepthStencilView> depthStencilView;
	// ������� Direct2d
	ComPtr<ID2D1Factory2> d2dFactory;
	ComPtr<ID2D1Device1> d2dDevice;
	ComPtr<ID2D1DeviceContext> d2dDevcon;
	ComPtr<ID2D1Bitmap1> d2dTargetBitmap;
	// ������� DirectWrite
	ComPtr<IDWriteFactory2> dwriteFactory;
	ComPtr<IWICImagingFactory2> wicFactory;

	D3D_FEATURE_LEVEL featureLevel;
	void AdaptToWindow(WindowDescriptor wd);
private:
	void CreateFactories();
	void CreateDeviceResources();
#if defined(_DEBUG)
	// ��������� ��������� ������� ������ SDK.
	inline bool SdkLayersAvailable()
	{
		HRESULT hr = D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_NULL,       // ��� ������������� ��������� ��������� ���������� ����������.
			0,
			D3D11_CREATE_DEVICE_DEBUG,  // ��������� ������ ������ SDK.
			nullptr,                    // ������� ����� �������������� �������.
			0,
			D3D11_SDK_VERSION,          // ������ ������������� ������ D3D11_SDK_VERSION ��� ���������� ��� �������� Windows.
			nullptr,                    // ��� ������������� ��������� ������ �� ���������� D3D.
			nullptr,                    // ��� ������������� ����� �������������� �������.
			nullptr                     // ��� ������������� ��������� ������ �� �������� ���������� D3D.
			);

		return SUCCEEDED(hr);
	}
#endif
};

