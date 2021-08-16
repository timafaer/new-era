#include "pch.h"
#include "new_eraMain.h"
#include "Common\DirectXHelper.h"

using namespace new_era;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

// ������������ �� ������� "���������� DirectX 12" ��. �� ������ https://go.microsoft.com/fwlink/?LinkID=613670&clcid=0x419

// ��������� � �������������� ������� ���������� �� ����� ��� ��������.
new_eraMain::new_eraMain()
{
	// TODO: �������� ��������� �������, ���� ��������� �����, �������� �� ������ �� ��������� � ���������� ����� �� �������.
	// ��������, ��� ������ ���������� � ������������� ��������� ����� 60 ������ � ������� ��������:
	/*
	m_timer.SetFixedTimeStep(true);
	m_timer.SetTargetElapsedSeconds(1.0 / 60);
	*/
}

// ������� � �������������� ��������������.
void new_eraMain::CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources)
{
	// TODO: �������� ��� �������������� ����������� ������ ����������.
	m_sceneRenderer = std::unique_ptr<Sample3DSceneRenderer>(new Sample3DSceneRenderer(deviceResources));

	OnWindowSizeChanged();
}

// ��������� ��������� ���������� ���� ��� �� ����.
void new_eraMain::Update()
{
	// ���������� �������� �����.
	m_timer.Tick([&]()
	{
		// TODO: �������� ��� ��������� ���������� ����������� ������ ����������.
		m_sceneRenderer->Update(m_timer);
	});
}

// ������������ ������� ���� � ������������ � ������� ���������� ����������.
// ���������� �������� true, ���� ���� ��������� � ����� � �����������.
bool new_eraMain::Render()
{
	// �� �������� ��������� �����-���� ��������� �� ������� ����������.
	if (m_timer.GetFrameCount() == 0)
	{
		return false;
	}

	// ��������� �������� �����.
	// TODO: �������� ��� ��������� ��������� ����������� ������ ����������.
	return m_sceneRenderer->Render();
}

// ��������� ��������� ���������� ��� ��������� ������� ����, �������� ��� ��������� ���������� ����������
void new_eraMain::OnWindowSizeChanged()
{
	// TODO: �������� ��� �������������� ����������� ������ ���������� � ����������� �� �������.
	m_sceneRenderer->CreateWindowSizeDependentResources();
}

// ���������� ���������� � ��� ������������.
void new_eraMain::OnSuspending()
{
	// TODO: �������� ��� ������� ������������ ������ ����������.

	// ���������� ��������� ������ �������� ����� ��������� ������ ���������������� ����������, �������
	// ������������� ��������� ����� ���������, ����������� ���������� ����������� � ����� ���������.

	m_sceneRenderer->SaveState();

	// ���� ���������� ���������� ��������� �����������, ������� ������ ������� ��������,
	// ������������� ���������� ��� ������, ����� ��� ���� �������� ��� ������ ����������.
}

// ���������� ���������� � ���, ��� ��� ����� �� ��������������.
void new_eraMain::OnResuming()
{
	// TODO: �������� ��� �� ������ ������������� ������ ������ ����������.
}

// ���������� ������������� � ���, ��� ������� ���������� ���������� ����������.
void new_eraMain::OnDeviceRemoved()
{
	// TODO: ��������� ��� ��������� ������������� ��� ����������� ���������� � ���������� ������������
	// � ��� �������, ������� ����� ���������������.
	m_sceneRenderer->SaveState();
	m_sceneRenderer = nullptr;
}
