#include "framework.h"
#include "SRV.h"

SRV::SRV(wstring path)
{
    ScratchImage image;
    LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);

    // �ǹ��� ����� �۾�
    CreateShaderResourceView(DEVICE.Get(), image.GetImages(),
        image.GetImageCount(), image.GetMetadata(), srv.GetAddressOf());
}

SRV::~SRV()
{
}

void SRV::SetSRV(UINT slot)
{
    DC->PSSetShaderResources(slot, 1, srv.GetAddressOf());
}
