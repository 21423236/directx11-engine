#include <memory>
#include "DDSTextureLoader\DDSTextureLoader.h"
#include "common.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
//#include "IndexBuffer.h"
#include "debug.h"


class Renderer
{
public:
	Renderer(WindowDescriptor wd);
	~Renderer();
	void Render();

	/* ��� XNA math ����� ������������ �� 16 ������ */
	/*void* operator new(size_t i)
	{
		return _aligned_malloc(i, 16);
	}

		void operator delete(void* p)
	{
		_aligned_free(p);
	}*/
private:
	D3D_DRIVER_TYPE driverType;
	
	ID3D11Device*        device;
	ID3D11DeviceContext* deviceContext;
	IDXGISwapChain*      swapChain;

	ID3D11RenderTargetView* renderTargetView = nullptr;
	ID3D11Texture2D*        depthTexture = nullptr;         // �������� ������ ������
	ID3D11DepthStencilView* depthStencilView = nullptr;     // ������ ����, ����� ������

	ID3D11ShaderResourceView *textureRV = nullptr;
	ID3D11SamplerState *sampler = nullptr;

	DXGI_SWAP_CHAIN_DESC swapChainDescriptor;

	ID3D11RasterizerState* noCullingState;
	void createDevice(WindowDescriptor wd);

	Vertex       triangle[3];
	Shader       *shader;
	VertexBuffer *buf;
	//IndexBuffer  *ibuf;

	XMMATRIX world;
	XMMATRIX view;
	XMMATRIX projection;

	float angle;

	ID3D11Buffer* cbuf;
	MatrixBuffer cb;
	ConstantBuffer<MatrixBuffer>* matrices;
};

